####################################################      
#    CMakeLists.txt for Project root directory     #
#                                                  #
#          author - Prabhat-Kumar-42              #
#   github - https://github.com/Prabhat-Kumar-42   #
####################################################


# minimum cmake veriosn required
cmake_minimum_required(VERSION 3.22.1)

# Project Name
project(GraphAlgoritms)

# testing
enable_testing()  # remove this line to disable testing

#Include the CMakeLists.txt files from subdirectories
add_subdirectory(Header)
add_subdirectory(Implementation)
add_subdirectory(tests)
