# Header/CMakeLists.txt

# Create a library for your Graph and Algorithms headers
add_library(GraphHeaders INTERFACE)
target_include_directories(GraphHeaders INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

