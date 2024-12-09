#include <iostream>
#include <vector>

#include <memory>

class Entity; // Forward declaration

// Base Component class
class Component {
public:
    Entity* entity = nullptr; // The entity this component belongs to

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

    virtual ~Component() = default;
};
