cmake_minimum_required(VERSION 3.5)

project(Lab9 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lab9 main.cpp)
set_target_properties(Lab9
    PROPERTIES
    CXX_EXTENSIONS OFF
)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
endif()

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(Lab9 PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
