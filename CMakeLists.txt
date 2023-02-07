cmake_minimum_required(VERSION 3.10)
project(2d-game-engine)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions("-std=c++20")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

SET(SOURCES src/main.cpp src/Vec2.cpp src/CTransform.cpp src/CShape.cpp src/CBoundingBox.cpp src/Entity.cpp src/EntityManager.cpp src/Scene_Play.cpp src/GameEngine.cpp src/Physics.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})