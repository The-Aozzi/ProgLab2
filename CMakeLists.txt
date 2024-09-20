cmake_minimum_required(VERSION 3.14.0)
project(ProgLab2 VERSION 0.1.0 LANGUAGES C CXX)

set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable(ProgLab2 main.cpp)

target_compile_options(ProgLab2 PRIVATE -fconcepts)

file(COPY ${CMAKE_SOURCE_DIR}/ip_filter.tsv DESTINATION ${EXECUTABLE_OUTPUT_PATH})