#include <map>
#include <functional>

// Define an enum for key codes (platform-specific key codes should be mapped to these)
enum class KeyCode {
    W,
    A,
    S,
    D,
    SPACE,
    ESCAPE,
    // ... other keys
};

// Define an enum for mouse buttons
enum class MouseButton {
    LEFT,
    RIGHT,
    MIDDLE,
    // ... other buttons
};

// InputManager class
class InputManager {
public:
    InputManager();
    ~InputManager();

    // Update the state of inputs (should be called once per frame)
    void update();

    // Key state checks
    bool isKeyPressed(KeyCode key);
    bool isKeyReleased(KeyCode key);
    bool isKeyDown(KeyCode key);

    // Mouse state checks
    bool isMouseButtonPressed(MouseButton button);
    bool isMouseButtonReleased(MouseButton button);
    bool isMouseButtonDown(MouseButton button);

    // Register callbacks for specific key events
    void registerKeyPressCallback(KeyCode key, std::function<void()> callback);
    void registerKeyReleaseCallback(KeyCode key, std::function<void()> callback);

    // Mouse position getters
    int getMouseX();
    int getMouseY();

private:
    // Store the current and previous state to detect state changes
    std::map<KeyCode, bool> currentKeyStates;
    std::map<KeyCode, bool> previousKeyStates;
    std::map<MouseButton, bool> currentMouseStates;
    std::map<MouseButton, bool> previousMouseStates;

    // Callback maps
    std::map<KeyCode, std::function<void()>> keyPressCallbacks;
    std::map<KeyCode, std::function<void()>> keyReleaseCallbacks;

    // Mouse position
    int mouseX, mouseY;

    // Internal methods to update states
    void pollEvents(); // Should be implemented to poll events from the system
    void updateKeyState(KeyCode key, bool isPressed);
    void updateMouseState(MouseButton button, bool isPressed);
    void updateMousePosition(int x, int y);
};

// Definitions for InputManager methods
bool InputManager::isKeyPressed(KeyCode key) {
    return currentKeyStates[key] && !previousKeyStates[key];
}

bool InputManager::isKeyReleased(KeyCode key) {
    return !currentKeyStates[key] && previousKeyStates[key];
}

bool InputManager::isKeyDown(KeyCode key) {
    return currentKeyStates[key];
}

bool InputManager::isMouseButtonPressed(MouseButton button) {
    return currentMouseStates[button] && !previousMouseStates[button];
}

bool InputManager::isMouseButtonReleased(MouseButton button) {
    return !currentMouseStates[button] && previousMouseStates[button];
}

bool InputManager::isMouseButtonDown(MouseButton button) {
    return currentMouseStates[button];
}

// ... other method implementations ...

void InputManager::update() {
    // Copy current states to previous
    previousKeyStates = currentKeyStates;
    previousMouseStates = currentMouseStates;

    // Poll new events and update current states
    pollEvents();

    // Execute callbacks for key press and release events
    for (const auto& pair : keyPressCallbacks) {
        if (isKeyPressed(pair.first)) {
            pair.second(); // Execute callback
        }
    }
    for (const auto& pair : keyReleaseCallbacks) {
        if (isKeyReleased(pair.first)) {
            pair.second(); // Execute callback
        }
    }
}