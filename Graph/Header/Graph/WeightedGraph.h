/***************************************************
 *      Header file for Weighted Graph             *
 *                                                 *
 *         author - Prabhat-Kumar-42              *
 *  github - https://github.com/Prabhat-Kumar-42   *
 *                                                 *
 ***************************************************/

#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <unordered_map>
#include <vector>

class WeightedGraph {
private:
  const bool isWeighted =
      true; // Immutable flag to indicate if the graph is weighted
  std::unordered_map<int, std::vector<std::pair<int, int>>>
      adjList; // Adjacency list with weights

public:
  // Constructor to create a weighted graph
  WeightedGraph();

  // Function to add a unidirectional edge from 'src' to 'dest' with a given
  // 'weight'
  bool addUniDirectionalEdge(int src, int dest, int weight);

  // Function to add a bidirectional edge between 'src' and 'dest' with a given
  // 'weight'
  bool addBiDirectionalEdge(int src, int dest, int weight);

  // Function to check if an edge exists between 'src' and 'dest'
  bool isEdge(int src, int dest);

  // Function to retrieve whether the graph is weighted or not
  bool getIsWeighted() const;

  // Function to print the adjacency list representation of the graph
  void printGraph() const;

  // Function to add a vertex to the graph
  bool addVertex(int vertex);

  // Function to remove a vertex from the graph
  bool removeVertex(int vertex);

  // Function to get the number of vertices in the graph
  int getVertexCount() const;

  // Function to get the set of vertices in the graph
  std::vector<int> getVertices() const;

  // Remove a unidirectional edge from vertex u to v
  bool removeEdge(int src, int dest);

  // Remove a bidirectional edge between vertices u and v
  bool removeBiDirectionalEdge(int src, int dest);

  // Function to check if a vertex exists in the graph
  bool hasVertex(int vertex);

  // Function to get the weight of the edge between 'src' and 'dest'
  int getEdgeWeight(int src, int dest);

  // Other member functions...
};

#endif
