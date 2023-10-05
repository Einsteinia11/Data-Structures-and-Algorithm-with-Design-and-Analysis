####################################################      
#               tests/CMakeLists.txt               #
#                                                  #
#          aurthor - Prabhat-Kumar-42              #
#   github - https://github.com/Prabhat-Kumar-42   #
####################################################

# Include Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Create test executables
add_executable(graph_tests ../tests/graph_tests.cpp)
add_executable(weighted_graph_tests ../tests/weighted_graph_tests.cpp)

# Link the test executables with your implementations and Google Test
target_link_libraries(graph_tests PRIVATE GraphImplementations gtest gtest_main)
target_link_libraries(weighted_graph_tests PRIVATE GraphImplementations gtest gtest_main)

# Add test cases
add_test(NAME graph_tests COMMAND graph_tests)
add_test(NAME weighted_graph_tests COMMAND weighted_graph_tests)
