#include <memory>

#include "raylib.h"
#include "raymath.h"
#include "renderer.h"
#include "custom_types.h"
#include "animal.h"

void Renderer::render(const sh_ptr<Entity> &entity)
{
    std::shared_ptr<Animal> animal = std::static_pointer_cast<Animal>(entity);

    const Rectangle &body = animal->get_body();
    const Vector2 &face_dir = animal->get_face_dir();

    DrawRectanglePro(
        body, 
        Vector2{body.width / 2, body.height / 2}, 
        Vector2Angle(face_dir, Vector2Zero()) * RAD2DEG, 
        animal->get_color()    
        );
}
void Renderer::render(const std::vector<sh_ptr<Entity>> &all_entities)
{
    for (const sh_ptr<Entity> &entity : all_entities)
    {
        render(entity);
    }
}