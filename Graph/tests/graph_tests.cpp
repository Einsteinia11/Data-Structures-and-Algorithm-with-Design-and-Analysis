#include <gtest/gtest.h>
#include "../Header/Graph/Graph.h"

TEST(GraphTest, AddEdgesAndCheckAdjacency) {
    Graph graph(5);

    ASSERT_TRUE(graph.addBiDirectionalEdge(0, 1));
    ASSERT_TRUE(graph.addBiDirectionalEdge(0, 2));
    ASSERT_TRUE(graph.addBiDirectionalEdge(1, 3));

    ASSERT_TRUE(graph.isEdge(0, 1));
    ASSERT_TRUE(graph.isEdge(1, 0));
    ASSERT_TRUE(graph.isEdge(0, 2));
    ASSERT_TRUE(graph.isEdge(2, 0));
    ASSERT_TRUE(graph.isEdge(1, 3));
    ASSERT_TRUE(graph.isEdge(3, 1));

    // Add more test cases for Graph as needed...
}

// ALL test case will pass as it returns true if the edge
// has been removed or there's no edge between the vertices
// hence no false condition
TEST(GraphTest, RemoveEdges) {
    Graph graph(5);

    // Add some edges
    graph.addBiDirectionalEdge(0, 1);
    graph.addBiDirectionalEdge(0, 2);
    graph.addBiDirectionalEdge(1, 3);

    // Remove an edge
    ASSERT_TRUE(graph.removeEdge(0, 1));
    ASSERT_FALSE(graph.isEdge(0, 1)); // Edge should be removed

    // Remove a bidirectional edge
    ASSERT_TRUE(graph.removeBiDirectionalEdge(0, 2));
    ASSERT_FALSE(graph.isEdge(0, 2)); // Edge should be removed
    ASSERT_FALSE(graph.isEdge(2, 0)); // Bidirectional edge should be removed
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

