cmake_minimum_required(VERSION 3.0)

project(dodger)

set(SRCS
  src/main.cpp
  src/Game.cpp
  src/Enemy.cpp)

set(HEADERS
  src/Game.hpp
  src/Enemy.hpp)

add_executable(dodger ${SRCS} ${HEADERS})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics)
target_link_libraries(dodger ${SFML_LIBRARIES})
