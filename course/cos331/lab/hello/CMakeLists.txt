cmake_minimum_required(VERSION 3.17)
project(hello C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_EXTENSIONS OFF)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # lots of warnings - you should fix them
    add_compile_options(-Wall -Wextra -pedantic)
endif()

add_executable(hello main.c)