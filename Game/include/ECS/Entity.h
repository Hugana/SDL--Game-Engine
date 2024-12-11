#include "Component.h"

class Entity {
private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

public:

    void update() {
        for (auto& component : components) {
            component->update();
        }
    }


    void draw() {
        for (auto& component : components) {
            component->draw();
        }
    }


    bool isActive() const {
        return active;
    }


    void destroy() {
        active = false;
    }


    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... args) {
        T* component = new T(std::forward<TArgs>(args)...);
        component->entity = this; // Set the parent entity
        components.emplace_back(component); // Store it in the component list
        component->init();
        return *component;
    }


        template <typename T>
        T* getComponent() {
            for (auto& component : components) {
                if (T* casted = dynamic_cast<T*>(component.get())) {
                    return casted;
                }
            }
            return nullptr;
        }
};
