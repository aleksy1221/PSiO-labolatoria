cmake_minimum_required(VERSION 3.5)

project(sfml-klasy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sfml-klasy main.cpp)
set_target_properties(sfml-klasy
    PROPERTIES
    CXX_EXTENSIONS OFF
)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
endif()

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(sfml-klasy PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

