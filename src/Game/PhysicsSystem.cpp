#include "PhysicsSystem.h"

// En PhysicsSystem
void PhysicsSystem::update(float deltaTime) {
    world->Step(deltaTime, 6, 2);  // Argumentos comunes para la simulación

    auto view = scene->mRegistry.view<PhysicsComponent, TransformComponent>();
    for (auto entity : view) {
        auto& physicsComponent = view.get<PhysicsComponent>(entity);
        auto& transformComponent = view.get<TransformComponent>(entity);

        // Sincronizar la posición y orientación
        const b2Vec2& position = physicsComponent.body->GetPosition();
        transformComponent.x = position.x;
        transformComponent.y = position.y;
    }
}
