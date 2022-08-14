cmake_minimum_required(VERSION 3.14)

# declare variable
set(PROJECT_NAME cmake_project_example)
# CMAKE_* -> predefined variable
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} src/main.cpp)