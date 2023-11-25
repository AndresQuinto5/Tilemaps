#include <iostream>
#include <SDL2/SDL.h>

#include "./System.h"
#include "./Components.hpp"
#include "../Game/PhysicsComponent.h"

const uint16 CATEGORY_PLAYER = 0x0001;
const uint16 CATEGORY_ENEMY = 0x0002;
const float PIXELS_PER_METER = 50;
const float SPRITE_SIZE_PIXELS = 50.0f;

class CharacterSetupSystem : public SetupSystem {
    private:
        SDL_Renderer* renderer;
        b2World* world;
    public:
        // CharacterSetupSystem(SDL_Renderer* r) : renderer(r) {}
        // Constructor modificado para CharacterSetupSystem y EnemySetupSystem
        CharacterSetupSystem(SDL_Renderer* r, b2World* world) : renderer(r), world(world) {}

        ~CharacterSetupSystem() {}

        void run() override {

          Entity player = scene->createEntity(
            "PLAYER",
            4,
            5
          );
          player.addComponent<MovementComponent>(0, 0);
          player.addComponent<SpriteComponent>(0, 2, 15, 0, 0, 50, 0);
          scene->player = new Entity(player);
          b2BodyDef bodyDef;
          bodyDef.type = b2_dynamicBody;  // o b2_staticBody para objetos estáticos
          bodyDef.position.Set(4 , 5);

          b2Body* body = world->CreateBody(&bodyDef);
          
          b2PolygonShape shape;
          float colliderHalfWidth = (SPRITE_SIZE_PIXELS ) / PIXELS_PER_METER;
          float colliderHalfHeight = (SPRITE_SIZE_PIXELS ) / PIXELS_PER_METER;
          shape.SetAsBox(colliderHalfWidth, colliderHalfHeight);

          b2FixtureDef fixtureDef;
          fixtureDef.shape = &shape;
          fixtureDef.density = 1.0f;
          fixtureDef.friction = 0.3f;
          fixtureDef.filter.categoryBits = CATEGORY_PLAYER;
          fixtureDef.filter.maskBits = CATEGORY_ENEMY;
          body->CreateFixture(&fixtureDef);

          // Añadir el PhysicsComponent a la entidad
          player.addComponent<PhysicsComponent>(body);
        }
};

class EnemySetupSystem : public SetupSystem {
    private:
        SDL_Renderer* renderer;
        b2World* world;
    public:
        // EnemySetupSystem(SDL_Renderer* r) : renderer(r) {}
        // Constructor modificado para CharacterSetupSystem y EnemySetupSystem
        EnemySetupSystem(SDL_Renderer* r, b2World* world) : renderer(r), world(world) {}

        ~EnemySetupSystem() {}

        void run() override {

          Entity enemy = scene->createEntity(
            "ENEMY",
            22,
            13
          );
          enemy.addComponent<MovementComponent>(0, 0);
          enemy.addComponent<SpriteComponent>(1, 2, 25, 0, 0, 55, 0);
          scene->enemy = new Entity(enemy);
          b2BodyDef bodyDef;
          bodyDef.type = b2_dynamicBody;  // o b2_staticBody para objetos estáticos
          bodyDef.position.Set(22 , 13 );

          b2Body* body = world->CreateBody(&bodyDef);

          b2PolygonShape shape;
          float colliderHalfWidth = (SPRITE_SIZE_PIXELS ) / PIXELS_PER_METER;
          float colliderHalfHeight = (SPRITE_SIZE_PIXELS ) / PIXELS_PER_METER;
          shape.SetAsBox(colliderHalfWidth, colliderHalfHeight);

          b2FixtureDef fixtureDef;
          fixtureDef.shape = &shape;
          fixtureDef.density = 1.0f;
          fixtureDef.friction = 0.3f;
          fixtureDef.filter.categoryBits = CATEGORY_ENEMY;
          fixtureDef.filter.maskBits = CATEGORY_PLAYER;
          body->CreateFixture(&fixtureDef);
          // Añadir el PhysicsComponent a la entidad
          enemy.addComponent<PhysicsComponent>(body);
        }
};


class CameraSetupSystem : public SetupSystem {
    private:
      int viewportWidth;
      int viewportHeight;
      int worldWidth;
      int worldHeight;
      int zoom;

    public:
        CameraSetupSystem(int z, int vw, int vh, int ww, int wh) : 
          zoom(z),
          viewportWidth(vw),
          viewportHeight(vh),
          worldWidth(ww),
          worldHeight(wh)
        {}

        void run() override {
          Entity camera = scene->createEntity("CAMERA",
            0,
            0 
          );
          camera.addComponent<CameraComponent>(
            zoom,
            viewportWidth,
            viewportHeight,
            worldWidth,
            worldHeight
          );
          scene->mainCamera = new Entity(camera);
        }
};

bool playedAction = false;
class PlayerInputSystem : public InputSystem {
  public:
    void run(SDL_Event event) override {
      auto& playerMovement = scene->player->getComponent<MovementComponent>();
      auto& playerSprite = scene->player->getComponent<SpriteComponent>();

      int speed = 400;

      if (event.type == SDL_KEYDOWN)
      {
        switch (event.key.keysym.sym) {
          case SDLK_a:
            playerMovement.vx = -speed;
            break;
          case SDLK_d:
            playerMovement.vx = speed;
            break;
          case SDLK_w:
            playerMovement.vy = -speed;
            break;
          case SDLK_s:
            playerMovement.vy = speed;
            break;
          case SDLK_o:
            if (!playedAction){
              playerSprite.y = 2;
              playedAction = true;
            }
            
            break;
          case SDLK_p:
            if (!playedAction){
              playerSprite.y = 3;
              playedAction = true;
            }
            break;
        }
      }  
      if (event.type == SDL_KEYUP)
      {
        switch (event.key.keysym.sym) {
          case SDLK_a:
            playerMovement.vx = 0;

            break;
          case SDLK_d:
            playerMovement.vx = 0;

            break;
          case SDLK_w:
            playerMovement.vy = 0;

          case SDLK_s:
            playerMovement.vy = 0;
          
          case SDLK_o:
            playedAction = false;
            break;
          
          case SDLK_p:
            playedAction = false;
            break;


        }
      }

      if (playerMovement.vx < 0) {
        playerSprite.x = 1;
      }
      else if (playerMovement.vx > 0) {
        playerSprite.x = 0;
      }

    }
};

class MovementUpdateSystem : public UpdateSystem {
public:
    void run(double dT) override {
        const auto view = scene->mRegistry.view<TransformComponent, MovementComponent, PhysicsComponent, TagComponent>();

        for (const entt::entity e : view) {
            auto& pos = view.get<TransformComponent>(e);
            auto& vel = view.get<MovementComponent>(e);
            auto& physics = view.get<PhysicsComponent>(e);
            const auto& tag = view.get<TagComponent>(e);

            // Actualizar la velocidad en Box2D
            b2Vec2 newVelocity(vel.vx / PIXELS_PER_METER, vel.vy / PIXELS_PER_METER); // Convertir velocidad a metros/segundo
            physics.body->SetLinearVelocity(newVelocity);

            // Actualizar la posición del sprite basada en la posición de Box2D
            const b2Vec2& physicsPos = physics.body->GetPosition();
            pos.x = physicsPos.x * PIXELS_PER_METER;
            pos.y = physicsPos.y * PIXELS_PER_METER;

            // Mantener al enemigo dentro de los límites definidos
            if (tag.tag == "ENEMY") {
                // Convertir los límites a metros para trabajar con Box2D
                const float minX = 130 / PIXELS_PER_METER;
                const float maxX = 1200 / PIXELS_PER_METER;

                if (physics.body->GetPosition().x <= minX) {
                    physics.body->SetLinearVelocity(b2Vec2(200 / PIXELS_PER_METER, 0)); // Mover hacia la derecha
                }
                if (physics.body->GetPosition().x >= maxX) {
                    physics.body->SetLinearVelocity(b2Vec2(-200 / PIXELS_PER_METER, 0)); // Mover hacia la izquierda
                }
            }
        }
    }
};




class CameraFollowUpdateSystem : public UpdateSystem {
    public:
        void run(double dT) override {
          auto playerTransform = scene->player->getComponent<TransformComponent>();
          auto cameraComponent = scene->mainCamera->getComponent<CameraComponent>();
          auto& cameraTransform = scene->mainCamera->getComponent<TransformComponent>();

          int px = playerTransform.x - cameraComponent.vw / 2 + 12 * cameraComponent.zoom;
          int py = playerTransform.y - cameraComponent.vh / 2 + 12 * cameraComponent.zoom;

          if (px > 0 && px < cameraComponent.ww - cameraComponent.vw) {
            cameraTransform.x = playerTransform.x - cameraComponent.vw / 2 + 12 * cameraComponent.zoom;
          }

          if (py > 0 && py < cameraComponent.wh - cameraComponent.vh) {
            cameraTransform.y = playerTransform.y - cameraComponent.vh / 2 + 12 * cameraComponent.zoom;
          }
        }
};

class SpriteRenderSystem : public SetupSystem, public UpdateSystem, public RenderSystem {
  private:
      SDL_Renderer* renderer;
      SDL_Window* window;
      int FPS;
      std::string name;
      
      const std::string spritesheets[2] = {
          "./assets/Titus.png",
          "./assets/ogre.png",
      };

      SDL_Texture* tilesets[1];
    public:
        SpriteRenderSystem(SDL_Renderer* r, SDL_Window* w, int fps) : renderer(r), window(w), FPS(fps) {}

        ~SpriteRenderSystem() {}

        void run() override {
          for(int i = 0; i < 2; i++) {
            SDL_Surface* surface = IMG_Load(spritesheets[i].c_str());
            tilesets[i] = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
          }
        }

        void run(double dT) override {
          const auto view = UpdateSystem::scene->mRegistry.view<SpriteComponent>();

          Uint32 current = SDL_GetTicks();

          for (const entt::entity e : view) {
            auto& sprite = view.get<SpriteComponent>(e);

            if (sprite.durationSeconds > 0) {
              float animdT = (current - sprite.lastUpdate) / 1000.0f;
              float animFps = sprite.durationSeconds/FPS;
              int framesToUpdate = animdT/animFps;

              if (framesToUpdate > 0) {
                sprite.y += framesToUpdate;
                sprite.y %= sprite.frames;
                sprite.lastUpdate = current;
              }
            }
          }
        }

        void run(SDL_Renderer* renderer) override {
          auto cameraTransform = RenderSystem::scene->mainCamera->getComponent<TransformComponent>();
          auto cameraZoom = RenderSystem::scene->mainCamera->getComponent<CameraComponent>().zoom;
          const int cx = cameraTransform.x;
          const int cy = cameraTransform.y;

          const auto view = RenderSystem::scene->mRegistry.view<TransformComponent, SpriteComponent>();
          for (const entt::entity e : view) {
            const auto& pos = view.get<TransformComponent>(e);
            const auto& sprite = view.get<SpriteComponent>(e);

            const int dstTileSize = cameraZoom * sprite.size;
            const int spriteX = sprite.x * sprite.size;
            const int spriteY = sprite.y * sprite.size;

            SDL_Rect src = { spriteX, spriteY, sprite.size, sprite.size };
            SDL_Rect dst = { pos.x - cx, pos.y - cy, dstTileSize, dstTileSize };

            SDL_RenderCopy(renderer, tilesets[sprite.sheetIndex], &src, &dst);

            // Ajustar la posición y tamaño del collider
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Color rojo para el collider

            // Ajusta estos valores según la proporción real del dibujo dentro de la imagen
            const float colliderWidthRatio = 0.6f; // Ejemplo: 80% del ancho del sprite
            const float colliderHeightRatio = 1.0f; // Ejemplo: 80% de la altura del sprite

            const int colliderWidth = static_cast<int>(dstTileSize * colliderWidthRatio);
            const int colliderHeight = static_cast<int>(dstTileSize * colliderHeightRatio);
            const int colliderX = pos.x + (dstTileSize - colliderWidth) / 2 - cx;
            const int colliderY = pos.y + (dstTileSize - colliderHeight) / 2 - cy;

            SDL_Rect colliderRect = {colliderX, colliderY, colliderWidth, colliderHeight};
            SDL_RenderDrawRect(renderer, &colliderRect);
          }
        }
};

class KnockDownPointSystem : public InputSystem {
  private:
    int ko1 = 0;
    int ko2 = 0;

  public:

    void run(SDL_Event event) override {
        if (event.type == SDL_KEYDOWN)
      {
        switch (event.key.keysym.sym) {
          case SDLK_o:
            // Logica para revisar hizo land el punch
            point1();
            break;
          case SDLK_p:
            // Logica para revisar si recivio punch
            point2();
            break;
        }
      }  
    }

    void point1 (){
      ko1 ++;
      std::cout << "POINTS" << std::endl;
      std::cout << ko1 << " - " << ko2 << std::endl;
    }
    void point2 (){
      ko2 ++;
      std::cout << "POINTS" << std::endl;
      std::cout << ko1 << " - " << ko2 << std::endl;
    }
};

class TileMapSystem : public SetupSystem, public RenderSystem {
  private:
    SDL_Renderer* renderer;
    SDL_Window* window;

    constexpr static int x = 0;
    constexpr static int y = 0;
    constexpr static int tileWidth = 60;
    constexpr static int tileHeigth = 60;

    const std::string mmap = "assets/map.png";
    const std::string file = "assets/tiles.png";
    int tilesWidth;
    int tilesHeight;

    SDL_Rect* tilemap;

    SDL_Texture* texture;
    

  public:
    TileMapSystem(SDL_Renderer* r, SDL_Window* w) : renderer(r), window(w) {
      std::cout << "Tile map system started" << std::endl;
    }

    ~TileMapSystem() {
    }

    // setup
    void run() override {

      SDL_Surface* surface = IMG_Load(file.c_str());
      texture = SDL_CreateTextureFromSurface(renderer, surface);
      SDL_FreeSurface(surface);
  
      STexture* t = new STexture(renderer, window);
      t->load(mmap);
      tilesWidth = t->getWidth();
      tilesHeight = t->getHeight();
      const int totalTiles = tilesWidth * tilesHeight;

      tilemap = new SDL_Rect[totalTiles];

      for(int i = 0; i < totalTiles; i++) {
        Uint32 currentColor = t->getPixel(i);
        int r = ((int)(currentColor >> 16) & 0xff);
        int g = ((int)(currentColor >> 8) & 0xff);
        tilemap[i] = { r * 16, g * 16, 16, 16 };
      }
      
      delete t;
    }

    void run(SDL_Renderer* r) override {

      auto cameraTransform = RenderSystem::scene->mainCamera->getComponent<TransformComponent>();
      auto cameraZoom = RenderSystem::scene->mainCamera->getComponent<CameraComponent>().zoom;
      const int dstTileSize = cameraZoom * 16;
      const int cx = cameraTransform.x;
      const int cy = cameraTransform.y;

      SDL_Rect rect = { -cx, -cy, dstTileSize, dstTileSize };
      for(int i = 0; i < tilesHeight; i++) {
        for(int j = 0; j < tilesWidth; j++) {
          SDL_Rect src = tilemap[i*tilesWidth + j];
          SDL_RenderCopy(r, texture, &src, &rect);
          rect.x += tileWidth;
        }
        rect.x = -cx;
        rect.y += dstTileSize;
      }
    }
};
