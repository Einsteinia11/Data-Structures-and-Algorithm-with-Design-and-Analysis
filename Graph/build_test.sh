#!/bin/sh

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

