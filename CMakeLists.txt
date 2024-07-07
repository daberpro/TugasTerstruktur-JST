cmake_minimum_required(VERSION 3.28.0)
project(JST CXX)
add_executable(${PROJECT_NAME} main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -pthread")
include_directories(
    "${PROJECT_SOURCE_DIR}/Packages/include"
    "${PROJECT_SOURCE_DIR}/Packages/include/stb"
    "${PROJECT_SOURCE_DIR}/Packages/include/eigen3"
)
target_link_libraries(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/Packages/lib/libarmadillo.a" "${PROJECT_SOURCE_DIR}/Packages/lib/liblapack.a" "${PROJECT_SOURCE_DIR}/Packages/lib/libblas.a" "${PROJECT_SOURCE_DIR}/Packages/lib/libmatplot.a" "${PROJECT_SOURCE_DIR}/Packages/lib/Matplot++/libnodesoup.a" -lgfortran -lquadmath )

