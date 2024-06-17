#include <vector>
#include <string>
#include <memory>

// Basic Vector3 class for position, rotation, and scale
struct Vector3 {
    float x, y, z;

    Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
};

// Component class from which all specific components will inherit
class Component {
public:
    virtual ~Component() {}
    virtual void update(float deltaTime) = 0;
    // Other common component methods can be added here
};

// Entity class representing a game object with components
class Entity {
public:
    Entity(std::string id) : entityId(id) {}

    template<typename T, typename... Args>
    void addComponent(Args&&... args) {
        components.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
    }
    
    void update(float deltaTime) {
        for (auto& component : components) {
            component->update(deltaTime);
        }
        // Additional update logic for the Entity itself, if needed
    }

    // Getters and setters for position, rotation, scale
    Vector3 getPosition() const { return position; }
    void setPosition(const Vector3& pos) { position = pos; }
    Vector3 getRotation() const { return rotation; }
    void setRotation(const Vector3& rot) { rotation = rot; }
    Vector3 getScale() const { return scale; }
    void setScale(const Vector3& scl) { scale = scl; }

    // Entity identifier
    std::string getId() const { return entityId; }

private:
    std::vector<std::unique_ptr<Component>> components;
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
    std::string entityId;
};

// Example components
class RenderComponent : public Component {
public:
    RenderComponent(/* render-specific parameters */) {
        // Constructor logic for the render component
    }

    void update(float deltaTime) override {
        // Update rendering logic, e.g., animation
    }

    // Render-specific methods
};

class PhysicsComponent : public Component {
public:
    PhysicsComponent(/* physics-specific parameters */) {
        // Constructor logic for the physics component
    }

    void update(float deltaTime) override {
        // Update physics logic, e.g., apply forces
    }

    // Physics-specific methods
};

class AIComponent : public Component {
public:
    AIComponent(/* AI-specific parameters */) {
        // Constructor logic for the AI component
    }

    void update(float deltaTime) override {
        // Update AI logic, e.g., decision making
    }

    // AI-specific methods
};

// Usage
int main() {
    Entity player("player1");

    // Add components to the player entity
    player.addComponent<RenderComponent>(/* render-parameters */);
    player.addComponent<PhysicsComponent>(/* physics-parameters */);
    player.addComponent<AIComponent>(/* AI-parameters */);

    // Game loop
    while (true) {
        float deltaTime = /* calculate delta time */;
        player.update(deltaTime);
        // Update other entities and game logic
    }

    return 0;
}