/***************************************************
 *           Tests for UnWeighted Graph            *
 *                                                 *
 *         aurthor - Prabhat-Kumar-42              *
 *  github - https://github.com/Prabhat-Kumar-42   *
 *                                                 *
 ***************************************************/

#include "../Header/Graph/Graph.h"
#include <gtest/gtest.h>

TEST(GraphTest, AddVertexAndCheckVertices) {
  Graph graph;

  ASSERT_TRUE(graph.addVertex(0));
  ASSERT_TRUE(graph.addVertex(1));
  ASSERT_TRUE(graph.addVertex(2));

  std::vector<int> vertices = graph.getVertices();
  ASSERT_EQ(vertices.size(), 3);
  ASSERT_TRUE(graph.hasVertex(0));
  ASSERT_TRUE(graph.hasVertex(1));
  ASSERT_TRUE(graph.hasVertex(2));
}

TEST(GraphTest, AddAndRemoveVertex) {
  Graph graph;

  ASSERT_TRUE(graph.addVertex(0));
  ASSERT_TRUE(graph.addVertex(1));
  ASSERT_TRUE(graph.addVertex(2));

  ASSERT_TRUE(graph.addBiDirectionalEdge(0, 1));
  ASSERT_TRUE(graph.addBiDirectionalEdge(0, 2));
  ASSERT_TRUE(graph.addUniDirectionalEdge(1, 2));

  ASSERT_TRUE(graph.removeVertex(0));
  ASSERT_FALSE(graph.isEdge(0, 1));
  ASSERT_FALSE(graph.isEdge(0, 2));
  ASSERT_FALSE(graph.isEdge(1, 0));
  ASSERT_FALSE(graph.isEdge(2, 0));

  std::vector<int> vertices = graph.getVertices();
  ASSERT_EQ(vertices.size(), 2);
  ASSERT_FALSE(graph.hasVertex(0));
  ASSERT_TRUE(graph.hasVertex(1));
  ASSERT_TRUE(graph.hasVertex(2));
}

TEST(GraphTest, AddEdgeAndCheckEdgeExistence) {
  Graph graph;

  ASSERT_TRUE(graph.addVertex(0));
  ASSERT_TRUE(graph.addVertex(1));

  ASSERT_TRUE(graph.addBiDirectionalEdge(0, 1));
  ASSERT_TRUE(graph.isEdge(0, 1));
  ASSERT_TRUE(graph.isEdge(1, 0));
}

TEST(GraphTest, RemoveEdge) {
  Graph graph;

  ASSERT_TRUE(graph.addVertex(0));
  ASSERT_TRUE(graph.addVertex(1));

  ASSERT_TRUE(graph.addBiDirectionalEdge(0, 1));
  ASSERT_TRUE(graph.removeBiDirectionalEdge(0, 1));

  ASSERT_FALSE(graph.isEdge(0, 1));
  ASSERT_FALSE(graph.isEdge(1, 0));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
