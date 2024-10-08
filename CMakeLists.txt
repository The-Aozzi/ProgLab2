cmake_minimum_required(VERSION 3.14.0)
project(ProgLab2 VERSION 0.1.0 LANGUAGES C CXX)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(ProgLab2 main.cpp utils.cpp)

target_compile_options(ProgLab2 PRIVATE -fconcepts)

file(COPY ${CMAKE_SOURCE_DIR}/ip_filter.tsv DESTINATION ${EXECUTABLE_OUTPUT_PATH})

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest 
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(tests tests.cpp utils.cpp)

target_link_libraries(tests gtest gtest_main)

install(TARGETS ProgLab2 DESTINATION bin)
install(FILES ip_filter.tsv DESTINATION bin)

set(CPACK_GENERATOR "DEB;ZIP")

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

add_test(NAME UnitTests COMMAND tests)