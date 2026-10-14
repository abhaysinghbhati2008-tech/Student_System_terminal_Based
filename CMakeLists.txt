cmake_minimum_required(VERSION 3.20)
project(Student_system LANGUAGES CXX)

set(CMAKE_C_STANDARD_REQUIRED 17)

set(cmake_minimum_required ON)

add_executable(Student_system
main.cpp
student.hpp
student.cpp
)
