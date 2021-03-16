cmake_minimum_required(VERSION 3.20.0)

set(This RUST_GENES)

project(${THIS} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(googletest)

set(Headers
    plant.hpp
)

set(Sources
    plant.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
add_subdirectory(test)


# add_executable(${PROJECT_NAME} main.cpp)