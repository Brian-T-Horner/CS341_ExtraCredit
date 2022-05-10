cmake_minimum_required(VERSION 3.20)
project(ExtraCredit)

set(CMAKE_CXX_STANDARD 20)

add_executable(ExtraCredit main.cpp StudentNode.cpp
        StudentLinkedList.cpp ClassLinkedList.cpp ClassNode.cpp)
