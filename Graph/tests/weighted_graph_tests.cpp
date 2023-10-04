#include <gtest/gtest.h>
#include "../Header/Graph/WeightedGraph.h"

TEST(WeightedGraphTest, AddEdgesAndCheckAdjacency) {
    WeightedGraph weightedGraph(5);

    ASSERT_TRUE(weightedGraph.addUniDirectionalEdge(0, 1, 10));
    ASSERT_TRUE(weightedGraph.addBiDirectionalEdge(0, 2, 20));
    ASSERT_TRUE(weightedGraph.addUniDirectionalEdge(1, 3, 30));

    ASSERT_TRUE(weightedGraph.isEdge(0, 1));
    ASSERT_FALSE(weightedGraph.isEdge(1, 0));
    ASSERT_TRUE(weightedGraph.isEdge(0, 2));
    ASSERT_TRUE(weightedGraph.isEdge(2, 0));
    ASSERT_TRUE(weightedGraph.isEdge(1, 3));
    ASSERT_FALSE(weightedGraph.isEdge(3, 1));

    // Add more test cases for WeightedGraph as needed...
}


// ALL test case will pass as it returns true if the edge
// has been removed or there's no edge between the vertices
// hence no false condition
TEST(WeightedGraphTest, RemoveEdges) {
    WeightedGraph weightedGraph(5);

    // Add some weighted edges
    weightedGraph.addBiDirectionalEdge(0, 1, 3);
    weightedGraph.addBiDirectionalEdge(0, 2, 2);
    weightedGraph.addBiDirectionalEdge(1, 3, 5);

    // Remove an edge
    ASSERT_TRUE(weightedGraph.removeEdge(0, 1));
    ASSERT_FALSE(weightedGraph.isEdge(0, 1)); // Edge should be removed

    // Remove a bidirectional edge
    ASSERT_TRUE(weightedGraph.removeBiDirectionalEdge(0, 2));
    ASSERT_FALSE(weightedGraph.isEdge(0, 2)); // Edge should be removed
    ASSERT_FALSE(weightedGraph.isEdge(2, 0)); // Bidirectional edge should be removed
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

