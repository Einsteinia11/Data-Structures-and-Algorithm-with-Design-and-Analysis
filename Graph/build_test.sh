#!/bin/sh

# Requirements -
#               1. cmake for building
#               2. google test for testing
#                     - can use online - uncomment the marked lines on tests/CMakeLists.txt
# Create a 'build' directory if it doesn't exist
mkdir -p ./build

# Change to the 'build' directory
cd ./build

# Configure the project with CMake
cmake ..

# Build the project using 'make'
make

# Run tests using 'ctest'
ctest

