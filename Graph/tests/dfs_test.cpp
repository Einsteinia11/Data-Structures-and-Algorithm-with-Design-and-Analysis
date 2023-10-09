/***************************************************
 *              Tests for DFS.cpp                  *
 *                                                 *
 *         author - Prabhat-Kumar-42               *
 *  github - https://github.com/Prabhat-Kumar-42   *
 *                                                 *
 ***************************************************/

#include "../Header/Algorithms/DFS.h"
#include "../Header/Graph/Graph.h"
#include "../Header/Graph/WeightedGraph.h"
#include "gtest/gtest.h"

// Test fixture for DFS class
class DFSTest : public ::testing::Test {
protected:
  Graph unweightedGraph;
  WeightedGraph weightedGraph;

  void SetUp() override {
    // Create an unweighted graph
    unweightedGraph.addVertex(0);
    unweightedGraph.addVertex(1);
    unweightedGraph.addVertex(2);
    unweightedGraph.addVertex(3);
    unweightedGraph.addBiDirectionalEdge(0, 1);
    unweightedGraph.addBiDirectionalEdge(0, 2);
    unweightedGraph.addBiDirectionalEdge(1, 3);

    // Create a weighted graph
    weightedGraph.addVertex(0);
    weightedGraph.addVertex(1);
    weightedGraph.addVertex(2);
    weightedGraph.addVertex(3);
    weightedGraph.addBiDirectionalEdge(0, 1, 5);
    weightedGraph.addBiDirectionalEdge(0, 2, 10);
    weightedGraph.addBiDirectionalEdge(1, 3, 7);
  }
};

TEST_F(DFSTest, RecursiveTraversalOnGraph) {
  DFS dfs(unweightedGraph);
  std::vector<int> dfsOrder = dfs.traverseRecursive(0);
  std::vector<int> expectedOrder = {0, 1, 3, 2};

  ASSERT_EQ(dfsOrder, expectedOrder);
}

TEST_F(DFSTest, NonRecursiveTraversalOnGraph) {
  DFS dfs(unweightedGraph);
  std::vector<int> dfsOrder = dfs.traverseNonRecursive(0);
  std::vector<int> expectedOrder = {0, 2, 1, 3};

  ASSERT_EQ(dfsOrder, expectedOrder);
}

TEST_F(DFSTest, RecursiveTraversalOnWeightedGraph) {
  DFS dfs(weightedGraph);
  std::vector<int> dfsOrder = dfs.traverseRecursive(0);
  std::vector<int> expectedOrder = {0, 1, 3, 2};

  ASSERT_EQ(dfsOrder, expectedOrder);
}

TEST_F(DFSTest, NonRecursiveTraversalOnWeightedGraph) {
  DFS dfs(weightedGraph);
  std::vector<int> dfsOrder = dfs.traverseNonRecursive(0);
  std::vector<int> expectedOrder = {0, 2, 1, 3};

  ASSERT_EQ(dfsOrder, expectedOrder);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
