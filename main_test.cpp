#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

#include "./include/raylib.h"
#include "./include/raymath.h"
#include "./src/geometry.h"

#define assertm(exp, msg) assert(((void)msg, exp))

struct Debug
{
    bool show_debug = true;
};

struct Config
{
    float win_h = 600;
    float win_w = 800;
    Color background_color = BLACK;
    float map_size = 250;
    Vec2 gravity = Vec2{0.0f, 1000.0f};
    float velocity_multiplier = 1;
};


static Config config = Config();

class Game
{
};

class VerletObj
{
    public:
        Vec2 pos_curr;
        Vec2 pos_prev;
        Vec2 acceleration;

        VerletObj(const Vec2 &start_pos): 
            pos_curr(start_pos), 
            pos_prev(start_pos),
            acceleration(Vec2(0.0, 0.0))
            {}
        void update_pos(float dt)
        {
            const Vec2 velocity = pos_curr.sub(pos_prev).scale(config.velocity_multiplier);
            pos_prev = pos_curr;
            pos_curr = pos_curr.add(velocity).add(acceleration.scale(dt * dt));
            acceleration = Vec2{0.0f, 0.0f};
        }
        void accelerate(const Vec2 &acc)
        {
            acceleration = acceleration.add(acc);
        }
};

class CircleObject: public VerletObj
{
    public:
        float radius;
        Color color;
        CircleObject(float _radius, Vec2 start_pos, Color color):
            VerletObj{start_pos}, radius(_radius), color(color){}
        void draw()
        {
            DrawCircle(pos_curr.x, pos_curr.y, radius, color); 
        };
};

class Solver
{
    private:
        const std::vector<CircleObject *> &m_objects;
        Vec2 gravity = config.gravity;
        std::vector<std::function<void(CircleObject *)>> operations;
        size_t m_substeps = 1;

    public:
        Solver(const std::vector<CircleObject *> &objects): m_objects(objects)
        {}
        void set_substeps(size_t steps)
        {
            assertm(steps > 0, "Steps cannot be less then 1");
            m_substeps = steps;
        }
        void resolve()
        {
            for (size_t i = 0; i < m_objects.size(); i++)
            {
                for (const auto &operation: operations)
                {
                    operation(m_objects[i]);                
                }
            }
            operations.clear();
        }
        void update_positions(float dt)
        {
            operations.push_back([dt](CircleObject * circle){
                 circle->update_pos(dt);
            });
        }
        void apply_gravity(const Vec2 &gravity)
        {
            operations.push_back([&](CircleObject * circle){
                 circle->accelerate(gravity);
            });
        }
        void apply_boundary(const CircleObject &container)
        {

            operations.push_back([&](CircleObject * circle){
                const Vec2 center_circle_dir = container.pos_curr.sub(circle->pos_curr);
                const float dist = sqrt(center_circle_dir.x * center_circle_dir.x + center_circle_dir.y * center_circle_dir.y);

                if (dist > (container.radius - circle->radius))
                {
                    const Vec2 n = center_circle_dir.reduce(dist);
                    circle->pos_curr = container.pos_curr.sub(n.scale(container.radius - circle->radius));
                }
            });
            // version2
            /*operations.push_back([&](const CircleObject * & circle){*/
            /*    const Vec2 center = container.pos_curr;*/
            /*    const float dist = circle->pos_curr.dist(center);*/
            /*    const float max_distance = dist + circle->radius;*/
            /**/
            /*    if (max_distance > container.radius)*/
            /*    {*/
            /*        const Vec2 center_to_obj = circle->pos_curr.sub(center);*/
            /*        const float n = (max_distance - dist) / (max_distance);*/
            /*        const Vec2 back_vec = center_to_obj.scale(-n);*/
            /*        circle->pos_curr = circle->pos_curr.add(back_vec);*/
            /*    }*/
            /*});*/
        }
        void apply_collision()
        {
            operations.push_back([this](const CircleObject * circle)
            {
                const float    response_coef = 0.75f;
                const uint64_t objects_count = m_objects.size();
                for (size_t i = 0; i < objects_count; ++i) 
                {
                CircleObject * object_1 = m_objects[i];
                    for (size_t k = i + 1; k < objects_count; ++k) 
                    {
                        CircleObject * object_2 = m_objects[k];
                        const Vec2 v = object_1->pos_curr.sub(object_2->pos_curr);
                        const float dist2 = v.x * v.x + v.y * v.y;
                        const float min_dist = object_1->radius + object_2->radius;
                        // Check overlapping
                        if (dist2 < min_dist * min_dist) 
                        {
                            const float dist  = sqrt(dist2);
                            const Vec2 n = v.reduce(dist);
                            const float mass_ratio_1 = object_1->radius / (object_1->radius + object_2->radius);
                            const float mass_ratio_2 = object_2->radius / (object_1->radius + object_2->radius);
                            const float delta = 0.5f * response_coef * (dist - min_dist);
                            // Update positions
                            object_1->pos_curr = object_1->pos_curr.sub(n.scale(mass_ratio_2 * delta));
                            object_2->pos_curr = object_2->pos_curr.add(n.scale(mass_ratio_1 * delta));
                        }
                    }
                }
                /*for (size_t i = 0; i < m_objects.size(); i++)*/
                /*{*/
                /*    for (size_t j = 0; j < m_objects.size(); j++)*/
                /*    {*/
                /*        if (i == j) continue;*/
                /*        const float dist_nosqrt = m_objects[i]->pos_curr.dist_nosqrt(m_objects[j]->pos_curr);*/
                /*        if (dist_nosqrt < pow(m_objects[i]->radius + m_objects[j]->radius, 2))*/
                /*        {*/
                /*            const Vec2 collision = m_objects[i]->pos_curr.sub(m_objects[j]->pos_curr).scale(0.5);*/
                /*            m_objects[i]->pos_curr = m_objects[i]->pos_curr.add(collision);*/
                /*            m_objects[j]->pos_curr = m_objects[j]->pos_curr.sub(collision);*/
                /*        }*/
                /*    }*/
                /*}*/
            });
        }
};

class Renderer
{
    private:
        const std::vector<CircleObject *> &m_objects;
    public:
        Renderer(const std::vector<CircleObject *> &objects):
            m_objects(objects)
        {}
        void render()
        {
            for (size_t i =0; i < m_objects.size(); i++)
            {
                m_objects[i]->draw();
            }
        }
};

const float MAX_BALL_RADIUS = 10;
const Vec2 CENTER = Vec2{config.win_w/2, config.win_h/2}; 
const Vec2 START_POS = Vec2{100, 300}; 
const Color BALL_COLOR = RED;
const Color CONTAINER_COLOR = GRAY;
const int SUB_STEPS = 4;

int main()
{
    std::cout << "START" << std::endl;
    CircleObject map_container = CircleObject(250, CENTER, CONTAINER_COLOR);  
    InitWindow(config.win_w, config.win_h, "HELLO WORLD");
    std::vector<CircleObject *> all_objects;
    all_objects.reserve(10000);
    Solver solver = Solver{all_objects};
    Renderer renderer = Renderer(all_objects);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(config.background_color);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) or IsKeyDown(KEY_A))
        {
            const Vec2 start_position = Vec2(GetMousePosition());
            all_objects.push_back(new CircleObject{MAX_BALL_RADIUS, start_position, BALL_COLOR});
        }
        if (IsKeyPressed(KEY_C))
        {
            for (int i = 0; i < all_objects.size(); i++)
            {
                delete all_objects[i]; 
            }
            all_objects.clear();
        }

        for (int i = 0; i < SUB_STEPS; i++)
        {
            solver.apply_gravity(config.gravity);
            solver.apply_boundary(map_container);
            solver.update_positions(dt/SUB_STEPS);
            solver.apply_collision();
            solver.resolve();
        }
        map_container.draw();
        renderer.render();
        EndDrawing();
        std::cout << "number of balls: " << all_objects.size() << std::endl;
    }

    std::cout << "DONE" << std::endl;
    return 0;
}
