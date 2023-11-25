// PhysicsSystem.h
#include "PhysicsComponent.h"
#include <box2d/box2d.h>

class PhysicsSystem : public UpdateSystem {
public:
    PhysicsSystem(b2World* world) : world(world) {
        contactListener = new MyContactListener();
        world->SetContactListener(contactListener);
        std::cout << "LISTENER DE CONTACT CREADO" << std::endl;

    }

    ~PhysicsSystem() {
        delete contactListener;
        std::cout << "LISTENER DESTROYED" << std::endl;

    }

    void run(double dT) override {
        world->Step(dT, 8, 3);

    }

private:
    b2World* world;
    MyContactListener* contactListener;
};