cmake_minimum_required(VERSION 3.2)

project(task3)

set(source_list check_value.h
                random_value.h
                high_scores.h
                argument.h
                main.cpp )

add_executable(proj ${source_list})
