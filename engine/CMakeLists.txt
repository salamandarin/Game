project(engine)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")
set(SDL2_INCLUDES "/opt/homebrew/include")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_subdirectory(util)
add_subdirectory(graphics)
add_subdirectory(map)
add_subdirectory(input)

add_library(engine
  action.cpp
  actor.cpp
  hero.cpp
  herotype.cpp
  monster.cpp
  monstertype.cpp
  weapon.cpp
  actors.cpp
  camera.cpp
  event.cpp
  events.cpp
  settings.cpp
  engine.cpp)

target_compile_features(engine PUBLIC cxx_std_17)
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(engine PUBLIC util graphics map input)
