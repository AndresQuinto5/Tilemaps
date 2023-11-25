cmake_minimum_required(VERSION 3.22)

project(MYGAME VERSION 1.0)

add_executable(${PROJECT_NAME} src/main.cpp src/Game/game.cpp src/Game/game.h src/Scene/Scene.cpp src/Scene/Scene.h)

include(FetchContent)
FetchContent_Declare(
    box2d
    GIT_REPOSITORY https://github.com/erincatto/box2d.git
    GIT_TAG v2.4.1  # Asegúrate de usar la versión más reciente
)

set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "Build the Box2D unit tests" FORCE)

FetchContent_MakeAvailable(box2d)

target_link_libraries(
    ${PROJECT_NAME}
    SDL2
    SDL2_image
    SDL2main
    box2d
)

