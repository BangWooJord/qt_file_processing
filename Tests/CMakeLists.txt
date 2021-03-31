cmake_minimum_required(VERSION 3.17)
project(tests)

set(CMAKE_CXX_STANDARD 17)

add_executable(tests main-test.cpp ../headers/file_related.h ../headers/toml_related.h ../src/file_related.cpp ../src/toml_related.cpp)
target_include_directories(tests PRIVATE ../headers ../src)