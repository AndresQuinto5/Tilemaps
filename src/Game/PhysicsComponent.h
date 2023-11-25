#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include <box2d/box2d.h>

struct PhysicsComponent {
    b2Body* body = nullptr;
    // Constructor, destructor, y cualquier función necesaria
};

class MyContactListener : public b2ContactListener {
public:
    void BeginContact(b2Contact* contact) override {
        if (!contact) return;

        b2Body* bodyA = contact->GetFixtureA()->GetBody();
        b2Body* bodyB = contact->GetFixtureB()->GetBody();

        // Puedes identificar los cuerpos aquí para ver si son el jugador o el enemigo
        std::cout << "Colisión entre dos cuerpos" << std::endl;
    }

    void EndContact(b2Contact* contact) override {
         std::cout << "Colisión terminada" << std::endl;
        // Manejar el fin de la colisión, si es necesario
    }
};

#endif // PHYSICSCOMPONENT_H
