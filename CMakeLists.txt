cmake_minimum_required(VERSION 3.0.0)
project(planwem VERSION 1.0.0)

add_executable(
    ${CMAKE_PROJECT_NAME}
    src/main.cpp
    src/draw/SvgGraphCanvas.cpp
    src/draw/StdoutGraphCanvas.cpp
    src/graph/SpringSystem.cpp
    src/graph/CycledSpringSystem.cpp)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE src)

target_link_libraries(${CMAKE_PROJECT_NAME} m)
target_link_libraries(${CMAKE_PROJECT_NAME} stdc++)

set_property(
    TARGET ${CMAKE_PROJECT_NAME}
    PROPERTY CXX_STANDARD 17
)
