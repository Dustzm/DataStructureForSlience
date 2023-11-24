cmake_minimum_required(VERSION 3.26)
project(DataStructureForSlience)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructureForSlience main.cpp)

add_executable(SequentialStack stack/SequentialStack.cpp)
add_executable(LinkedStack stack/LinkedStack.cpp)
add_executable(DoubleLinkedStack stack/DoubleLinkedStack.cpp)