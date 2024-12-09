class Manager {
    private:
        std::vector<std::unique_ptr<Entity>> entities; // List of all entities

    public:

        Entity& createEntity() {
            Entity* entity = new Entity();
            entities.emplace_back(entity);
            return *entity;
        }


        void update() {
            for (auto& entity : entities) {
                entity->update();
            }
        }

        void draw() {
            for (auto& entity : entities) {
                entity->draw();
            }
        }

        void refresh() {
            entities.erase(std::remove_if(entities.begin(), entities.end(),
                [](const std::unique_ptr<Entity>& entity) {
                    return !entity->isActive(); // Remove inactive entities
                }),
                entities.end());
        }
};
