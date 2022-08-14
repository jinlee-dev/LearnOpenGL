cmake_minimum_required(VERSION 3.14)

# declare variable
set(PROJECT_NAME cmake_project_example)
# CMAKE_* -> predefined variable
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} src/main.cpp)

include (Dependency.cmake)

# 우리 프로젝트에 include / lib 관련 옵션 추가
target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})

# Dependency가 먼저 컴파일 되어야 한다.
add_dependencies(${PROJECT_NAME} ${DEP_LIST})