/***************************************************
 *           Tests for Weighted Graph              *
 *                                                 *
 *         author - Prabhat-Kumar-42              *
 *  github - https://github.com/Prabhat-Kumar-42   *
 *                                                 *
 ***************************************************/

#include "../Header/Graph/WeightedGraph.h"
#include <gtest/gtest.h>

TEST(WeightedGraphTest, AddEdge) {
  WeightedGraph graph;

  // Add edges
  ASSERT_TRUE(graph.addBiDirectionalEdge(0, 1, 5));
  ASSERT_TRUE(graph.addUniDirectionalEdge(1, 2, 3));
  ASSERT_TRUE(graph.addBiDirectionalEdge(2, 3, 7));

  // Check if the edges were added successfully
  ASSERT_TRUE(graph.isEdge(0, 1));
  ASSERT_TRUE(graph.isEdge(1, 0)); // Should be bidirectional
  ASSERT_TRUE(graph.isEdge(1, 2));
  ASSERT_FALSE(graph.isEdge(0, 2)); // No direct edge between 0 and 2
}

TEST(WeightedGraphTest, RemoveEdge) {
  WeightedGraph graph;

  // Add edges
  graph.addBiDirectionalEdge(0, 1, 5);
  graph.addUniDirectionalEdge(1, 2, 3);

  // Remove edges
  ASSERT_TRUE(graph.removeEdge(0, 1));
  ASSERT_FALSE(graph.isEdge(0, 1)); // Edge should be removed
  ASSERT_TRUE(graph.isEdge(1, 2));  // Other edges should still exist

  // Remove a non-existent edge
  ASSERT_FALSE(graph.removeEdge(0, 1));
}

TEST(WeightedGraphTest, AddVertex) {
  WeightedGraph graph;

  // Add vertices
  ASSERT_TRUE(graph.addVertex(0));
  ASSERT_TRUE(graph.addVertex(1));

  // Attempt to add a duplicate vertex
  ASSERT_FALSE(graph.addVertex(0));
}

TEST(WeightedGraphTest, RemoveVertex) {
  WeightedGraph graph;

  // Add vertices and edges
  graph.addBiDirectionalEdge(0, 1, 5);
  graph.addUniDirectionalEdge(1, 2, 3);

  // Remove a vertex
  ASSERT_TRUE(graph.removeVertex(0));
  ASSERT_FALSE(graph.hasVertex(0)); // Vertex should be removed
  ASSERT_FALSE(
      graph.isEdge(0, 1)); // Edges connected to 0 should also be removed
  ASSERT_TRUE(graph.isEdge(1, 2)); // Other edges should still exist

  // Attempt to remove a non-existent vertex
  ASSERT_FALSE(graph.removeVertex(3));
}

TEST(WeightedGraphTest, GetEdgeWeight) {
  WeightedGraph graph;

  // Add edges with weights
  graph.addBiDirectionalEdge(0, 1, 5);
  graph.addUniDirectionalEdge(1, 2, 3);

  // Get edge weights
  ASSERT_EQ(graph.getEdgeWeight(0, 1), 5);
  ASSERT_EQ(graph.getEdgeWeight(1, 0), 5); // Bidirectional edge
  ASSERT_EQ(graph.getEdgeWeight(1, 2), 3);
  ASSERT_EQ(graph.getEdgeWeight(0, 2), -1); // Non-existent edge
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
