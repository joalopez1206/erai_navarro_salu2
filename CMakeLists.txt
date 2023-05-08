cmake_minimum_required(VERSION 3.20)
project(Tarea1log CXX)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
    src/utils.cpp
    src/main.cpp
    src/inv_perm.cpp
    src/merge_sort.cpp)

add_executable(Tarea1log ${SOURCE_FILES})
target_include_directories(Tarea1log PUBLIC include)
