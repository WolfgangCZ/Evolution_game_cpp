#pragma once

#include <vector>
#include <functional>
#include <cassert>

#include "../../include/raylib.h"
#include "../config.h"
#include "w_object.h"
#include "circle.h"
#include "grid.h"
#include "settings.h"

#define assertm(exp, msg) assert(((void)msg, exp));

namespace wEng
{
    class WSolver
    {
        private:
            const std::vector<CircleObject *> &m_objects;
            std::vector<std::function<void(CircleObject *)>> operations;
            size_t m_substeps = settings.sub_steps;
            SolverGrid<CircleObject> grid;

        public:
            WSolver(const std::vector<CircleObject *> &objects): m_objects(objects), grid(SolverGrid<CircleObject>{})
            {
            }
            const SolverGrid<CircleObject> &get_grid() const
            {
                return grid;
            }
            void place_objects()
            {
                grid.clear();
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
            }

            void update_positions(float dt)
            {
                const float step_dt = get_step_dt(dt);
                operations.push_back([step_dt, this](CircleObject * circle){
                    circle->update_position(step_dt);
                });
            }
            std::list<GridBox<CircleObject> *> get_adjacent_boxes(int col, int row)
            {
                std::list<GridBox<CircleObject> *> list;
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
            void apply_boundary()
            {
                operations.push_back([&](CircleObject * circle){
                    const float boundary_width = grid.box_w * (grid.cols - 1);
                    const float boundary_height = grid.box_h * (grid.rows - 1);
                    if (circle->position.x - circle->radius < grid.box_w)
                    {
                        circle->position.x = circle->radius + grid.box_w;
                        circle->velocity.x = -circle->velocity.x;
                    }
                    else if (circle->position.x + circle->radius > boundary_width)
                    {
                        circle->position.x = boundary_width - circle->radius;
                        circle->velocity.x = -circle->velocity.x;
                    }
                    if (circle->position.y - circle->radius < grid.box_h)
                    {
                        circle->position.y = circle->radius + grid.box_h;
                        circle->velocity.y = -circle->velocity.y;
                    }
                    else if (circle->position.y + circle->radius > boundary_height)
                    {
                        circle->position.y = boundary_height - circle->radius;
                        circle->velocity.y = -circle->velocity.y;
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
                        GridBox<CircleObject> &this_box = grid.boxes[col][row];
                        if (this_box.checked) continue;
                        std::list<GridBox<CircleObject> *> adj_boxes = get_adjacent_boxes(col, row);
                        for (auto it_adj_box = adj_boxes.begin(); it_adj_box != adj_boxes.end(); ++it_adj_box) 
                        {
                            const GridBox<CircleObject> * close_box = *it_adj_box;
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

                                        float force_absorb = 1.0f;
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
}
