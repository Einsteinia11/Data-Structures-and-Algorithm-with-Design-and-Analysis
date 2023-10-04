# Implementation/CMakeLists.txt

# Create a library for your Graph and Algorithms implementations
add_library(GraphImplementations
    Graph/Graph.cpp
    Graph/WeightedGraph.cpp
    #    Algorithms/...  # Add other source files as needed
)

# Link the headers library to your implementations
target_link_libraries(GraphImplementations PUBLIC GraphHeaders)

