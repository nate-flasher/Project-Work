cmake_minimum_required(VERSION 3.17)
project(nflasher C)

set(CMAKE_C_STANDARD 11)

add_executable(nflasher main.c course/cos331/lab/RFT/RFTcodetogether.c)