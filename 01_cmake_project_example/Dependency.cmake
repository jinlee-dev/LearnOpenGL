# ExternalProject -> ExternalProject_Add 기능을 사용하기 위해 include
include(ExternalProject)

# Dependency 관련 변수 설정
# DEP_INSTALL_DIR -> Lib 설치 경로
# PROJECT_BINARY_DIR -> predefined variable -> build folder/install
set(DEP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install)
# download all header file to build/include
set(DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include)
# download lib file in build/lib
set(DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib)

# External Project Add -> Download and execute cmake
ExternalProject_Add(
    dep-spdlog
    GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
    GIT_TAG "v1.x"
    GIT_SHALLOW 1
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
    TEST_COMMAND ""
)

# Dependency 리스트 및 라이브러리 파일 리스트 추가
set(DEP_LIST ${DEP_LIST} dep-spdlog)
set(DEP_LIBS ${DEP_LIBS} spdlog$<$<CONFIG:Debug>:d>)
