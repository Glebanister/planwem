cmake_minimum_required(VERSION 3.0.0)
project(planwem VERSION 1.0.0)

add_executable(
    ${CMAKE_PROJECT_NAME}
    src/main.cpp
    src/draw/SvgGraphCanvas.cpp
    src/draw/StdoutGraphCanvas.cpp
    src/graph/SpringGraph.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC include)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE src)

set_property(
    TARGET ${CMAKE_PROJECT_NAME}
    PROPERTY CXX_STANDARD 17
)
