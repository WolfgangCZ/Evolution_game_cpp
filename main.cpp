#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <format>
#include <cassert>
#include <chrono>
#include <cstring>



#include "./include/raylib.h"
#include "./include/raymath.h"
#include "./src/geometry.h"
#include "./src/assert.h"
#include "./src/random.h"


// hello
static size_t collision_checks = 0;
static size_t obj_created = 0;

struct Debug
{
    bool show_debug = true;
};

struct Config
{
    const float win_h = 900;
    const float win_w = 1600;
    const Color background_color = BLACK;
    const float map_size = 250;
    const Vector2 gravity_force = Vector2{0.0f, 500.0f};
    const float friction = 0.9f;
};


void mark_check(int num)
{
    std::cout << "check " << num << std::endl;
}


static Config config = Config();

class Game
{
};

class PhysicsObject
{
    public:
        size_t id = 0;
        Vector2 position;
        Vector2 velocity;

        PhysicsObject(const Vector2 &start_pos): 
            id(obj_created++),
            position(start_pos), 
            velocity(Vector2{RAND_FLOAT(-100, 100), RAND_FLOAT(-100, 100)})
            {}
        void update_position(float dt)
        {
            position = Vector2Add(position, Vector2Scale(velocity, dt));            
        }
        void add_velocity(const Vector2 &vel)
        {
            velocity = Vector2Add(velocity, vel);
        }
};

class CircleObject: public PhysicsObject
{
    private:
        float inv_mass;
    public:
        float radius;
        float mass;
        Color color;
        void set_id(size_t id)
        {
            this->id = id;
        }
        CircleObject(float _radius, Vector2 start_pos, Color color):
            PhysicsObject{start_pos}, radius(_radius), color(color)
            {
               mass = PI * radius * radius;
                inv_mass = 1.0f / mass;
            }
        void draw()
        {
            DrawCircleV(position, radius, color); 
        };
        float get_inv_mass() const
        {
            return inv_mass;
        }
};

struct GridBox
{
    int col;
    int row;
    bool checked = false;
    std::list<CircleObject *> obj_list;
};

struct SolverGrid
{
    int rows;
    int cols;
    float box_w;
    float box_h;
    std::vector<std::vector<GridBox>> boxes;
};

const float BOX_RATIO = 20.0f;
const int GRID_COLS = int(config.win_w / BOX_RATIO);
const int GRID_ROWS = int(config.win_h / BOX_RATIO);

class Solver
{
    private:
        const std::vector<CircleObject *> &m_objects;
        std::vector<std::function<void(CircleObject *)>> operations;
        size_t m_substeps = 1;
        SolverGrid grid;

    public:
        Solver(const std::vector<CircleObject *> &objects): m_objects(objects)
        {
            grid = init_grid();
        }
        const SolverGrid &get_grid() const
        {
            return grid;
        }
        SolverGrid init_grid()
        {
            std::vector<std::vector<GridBox>> obj_list;
            obj_list.resize(GRID_COLS);
            for (int col = 0; col < GRID_COLS; col++)
            {
                obj_list[col].resize(GRID_ROWS);
                for (int row = 0; row < GRID_ROWS; row++)
                {
                    std::list<CircleObject *> list;
                    GridBox box = {col, row, false, list};
                    obj_list[col][row] = box;
                }
            }
            return SolverGrid{
                GRID_ROWS,
                GRID_COLS,
                config.win_w / GRID_COLS,
                config.win_h / GRID_ROWS,
                obj_list,
            };
        }
        void place_objects()
        {
            clear_grid();
            for (size_t i = 0; i < m_objects.size(); i++)
            {
                CircleObject * circle = m_objects[i];
                int col = int(circle->position.x / grid.box_w);
                int row = int(circle->position.y / grid.box_h);
                grid.boxes[col][row].obj_list.push_back(circle);
            }
        }
        float get_step_dt(float dt)
        {
            return dt / m_substeps;
        }
        void set_substeps(size_t steps)
        {
            assertm(steps > 0, "Steps cannot be less then 1");
            m_substeps = steps;
        }
        void update()
        {
            for (size_t s = 0; s < m_substeps; s++)
            {
                place_objects();
                for (size_t i = 0; i < m_objects.size(); i++)
                {
                    for (size_t j = 0; j < operations.size(); j++)
                    {
                        operations[j](m_objects[i]);                
                    }
                }
            }
            operations.clear();
            collision_checks = 0;
        }

        void clear_grid()
        {
            for (int col = 0; col < GRID_COLS; col++)
            {
                for (int row = 0; row < GRID_ROWS; row++)
                {
                    grid.boxes[col][row].obj_list.clear();
                    grid.boxes[col][row].checked = false;
                }
            }

        }

        void update_positions(float dt)
        {
            const float step_dt = get_step_dt(dt);
            operations.push_back([step_dt, this](CircleObject * circle){
                circle->update_position(step_dt);
            });
        }
        std::list<GridBox *> get_adjacent_boxes(int col, int row)
        {
            std::list<GridBox *> list;
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (i == -1 && col == 0) continue;
                    if (i == 1 && col == grid.cols - 1) continue;
                    if (j == -1 && row == 0) continue;
                    if (j == 1 && row == grid.rows - 1) continue;
                    list.push_back(&grid.boxes[col + i][row + j]);
                }
            }
            return list;
        }
        void apply_gravity(const Vector2 &gravity)
        {
            operations.push_back([&](CircleObject * circle){
                const Vector2 gravity = Vector2Reduce(config.gravity_force, circle->mass);
                circle->add_velocity(gravity);
            });
        }
        void apply_boundary(const CircleObject &container)
        {
            operations.push_back([&](CircleObject * circle){
                float const dist_nosqrt = pow(circle->position.x - container.position.x, 2) +
                        pow(circle->position.y - container.position.y, 2);
                if (dist_nosqrt > pow(container.radius - circle->radius, 2))
                {
                    const Vector2 normal = Vector2Normalize(Vector2Subtract(circle->position, container.position));
                    circle->position = Vector2Add(container.position, Vector2Scale(normal, container.radius - circle->radius));
                    const float dot_product = Vector2DotProduct(circle->velocity, normal);
                    const float bounciness = 2;
                    circle->velocity = Vector2Subtract(circle->velocity, Vector2Scale(normal, bounciness * dot_product)); 
                }
            });
        }

        void apply_collision()
        {
            operations.push_back([this](const CircleObject * circle)
            {
                for (size_t i = 0; i < m_objects.size(); i++)
                {
                    const int col = int(m_objects[i]->position.x / grid.box_w);
                    const int row = int(m_objects[i]->position.y / grid.box_h);
                    GridBox &this_box = grid.boxes[col][row];
                    if (this_box.checked) continue;
                    std::list<GridBox *> adj_boxes = get_adjacent_boxes(col, row);
                    for (auto it_adj_box = adj_boxes.begin(); it_adj_box != adj_boxes.end(); ++it_adj_box) 
                    {
                        const GridBox * close_box = *it_adj_box;
                        if (close_box->checked || close_box->obj_list.empty()) continue;
                        for (auto it_obj1 = this_box.obj_list.begin(); it_obj1 != this_box.obj_list.end(); ++it_obj1)
                        {
                            CircleObject *obj1 = *it_obj1;
                            for (auto it_obj2 = (*it_adj_box)->obj_list.begin(); it_obj2 != (*it_adj_box)->obj_list.end(); ++it_obj2)
                            {
                                CircleObject *obj2 = *it_obj2;
                                if (obj1 == obj2) continue;
                                const float dist_nosqrt = pow(obj1->position.x - obj2->position.x, 2) +
                                                          pow(obj1->position.y - obj2->position.y, 2);
                                const float min_dist = obj1->radius + obj2->radius;
                                const float min_dist_pow = min_dist * min_dist;
                                collision_checks++;
                                if (dist_nosqrt < min_dist_pow) 
                                {
                                    const Vector2 displacement = Vector2Subtract(obj2->position, 
                                                                                obj1->position);
                                    const Vector2 normal = Vector2Normalize(displacement); 
                                    const Vector2 relative_velocity = Vector2Subtract(obj2->velocity,
                                                                                      obj1->velocity); 
                                    float vel_along_normal = Vector2DotProduct(relative_velocity, normal);
                                    const float dist = sqrt(dist_nosqrt);
                                    const float overlap = dist - obj1->radius - obj2->radius;
                                    const Vector2 push_back = Vector2Scale(normal, overlap/2);
                                    obj1->position = Vector2Add(obj1->position, push_back);
                                    obj2->position = Vector2Subtract(obj2->position, push_back);

                                    float force_absorb = 0.9f;
                                    float impulse = -2*force_absorb * vel_along_normal / (obj1->get_inv_mass() + obj2->get_inv_mass());
                                    obj1->add_velocity(Vector2Scale(normal, -impulse / obj1->mass));
                                    obj2->add_velocity(Vector2Scale(normal, impulse / obj2->mass));
                                }
                            }
                        }
                    }
                    this_box.checked = true;
                }
            });
        }
};


const float MAX_BALL_RADIUS = 5.0f;
const Vector2 CENTER = Vector2{config.win_w/2, config.win_h/2}; 
const Vector2 START_POS = Vector2{100, 300}; 
const Color CONTAINER_COLOR = GRAY;
const int SUB_STEPS = 1;
const int CONTAINER_RADIUS = config.win_h * 0.95 * 0.5;

template<typename T>
void safe_clear(std::vector<T> &vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        delete vector[i]; 
    }
    vector.clear();
}

std::string _float_label(std::string label, float value)
{
    return std::format("{}: {:.2f}", label, value);
}
std::string _int_label(std::string label, int value)
{
    return std::format("{}: {}", label, value);
}
int main()
{
    std::cout << "START" << std::endl;
    CircleObject map_container = CircleObject(CONTAINER_RADIUS, CENTER, CONTAINER_COLOR);  
    InitWindow(config.win_w, config.win_h, "HELLO WORLD");
    std::vector<CircleObject *> all_objects;
    all_objects.reserve(10000);
    Solver solver = Solver{all_objects};
    solver.set_substeps(SUB_STEPS);
    Renderer renderer = Renderer(all_objects);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // auto start = std::chrono::high_resolution_clock::now();
        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(config.background_color);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_A))
        {
            const Vector2 start_pos = Vector2(GetMousePosition());
            Color color = Color{RAND_CHAR, RAND_CHAR, RAND_CHAR, 255};
            all_objects.push_back(new CircleObject{RAND_FLOAT(5, (int)MAX_BALL_RADIUS), start_pos, color});
        }
        if (IsKeyPressed(KEY_C))
        {
            safe_clear(all_objects);
        }
        // solver.apply_gravity(config.gravity_force);
        solver.apply_boundary(map_container);
        solver.apply_collision();
        solver.update_positions(dt);
        solver.update();
        map_container.draw();
        renderer.render();
        DrawText(_int_label("Objects count: ", all_objects.size()).c_str(), 20, 20, 10, WHITE);
        DrawText(_float_label("FPS: ", 1/dt).c_str(), 20, 40, 10, WHITE);
        draw_grid(GRID_COLS, GRID_ROWS, config.win_w / GRID_COLS, config.win_h / GRID_ROWS);
        if (IsKeyPressed(KEY_S))
        {
            safe_clear(all_objects);
        }
        EndDrawing();
        /*std::cout << "FPS: " << 1/dt << std::endl;*/
        /*std::cout << "Number of objects: " << all_objects.size() << std::endl;*/
    }
   

    std::cout << "DONE" << std::endl;
    return 0;
}
