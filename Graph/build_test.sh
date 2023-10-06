#!/bin/sh

####################################################      
#            Build Script for Project              #
#                                                  #
#          author - Prabhat-Kumar-42               #
#   github - https://github.com/Prabhat-Kumar-42   #
####################################################


# Requirements -
#               1. cmake for building
#               2. google test for testing
#                     - can use online - uncomment the marked lines on tests/CMakeLists.txt


# How to use -
#           1. Place the script at the Project's root direcotry
#           2. Make sure the script is executable
#               - If not :
#                         run 'chmod 554 build_test.sh'
#           3. execute './build_test.sh'


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

