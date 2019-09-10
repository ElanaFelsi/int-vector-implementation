cmake_minimum_required(VERSION 3.14)
project(c_vector_of_ints_ElanaFelsi C)

set(CMAKE_C_STANDARD 90)

add_executable(c_vector_of_ints_ElanaFelsi main.c vector.h vector.c testing.h testing.c)