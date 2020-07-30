cmake_minimum_required(VERSION 3.16)
project(CCalc C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CCalc
        jccalculator.c
        jccalculator.h
        main.c)
