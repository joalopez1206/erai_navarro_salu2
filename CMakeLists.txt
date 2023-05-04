cmake_minimum_required(VERSION 3.12)
project(Tarea1log C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES
    src/utils.c
    src/main.c
    src/inv_perm.c
    src/merge_sort.c)

add_executable(Tarea1log ${SOURCE_FILES})
target_include_directories(Tarea1log PUBLIC include)
