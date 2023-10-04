cmake_minimum_required(VERSION 3.22.1)
project(GraphAlgoritms)
enable_testing()

#Include the CMakeLists.txt files from subdirectories
add_subdirectory(Header)
add_subdirectory(Implementation)
add_subdirectory(tests)
