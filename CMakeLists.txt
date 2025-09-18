cmake_minimum_required(VERSION 3.10)

project(fourier-transform)

aux_source_directory(./src SRC_MAIN)
add_executable(ft ${SRC_MAIN})
target_link_libraries(ft gtest sfml-system sfml-window sfml-graphics)
target_compile_options(ft PRIVATE "-std=c++26")

enable_testing()