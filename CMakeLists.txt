cmake_minimum_required(VERSION 3.1)

project(BullCowGame)
add_compile_options(-std=c++11)

include_directories(include)

add_executable(game 
               src/main.cpp
               src/FBullCowGame.cpp)