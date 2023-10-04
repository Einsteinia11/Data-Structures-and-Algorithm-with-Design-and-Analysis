#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <vector>

class WeightedGraph {
private:
    int V; // Number of vertices
    const bool isWeighted = true; // Immutable flag to indicate if the graph is weighted
    std::vector<std::vector<std::pair<int, int>>> adjList; // Adjacency list with weights

public:
    // Constructor to create a weighted graph with 'vertices' number of vertices
    WeightedGraph(int vertices);

    // Function to add a unidirectional edge from 'src' to 'dest' with a given 'weight'
    bool addUniDirectionalEdge(int src, int dest, int weight);

    // Function to add a bidirectional edge between 'src' and 'dest' with a given 'weight'
    bool addBiDirectionalEdge(int src, int dest, int weight);

    // Function to check if an edge exists between 'src' and 'dest'
    bool isEdge(int src, int dest);

    // Function to retrieve whether the graph is weighted or not
    bool getIsWeighted() const;

    // Function to print the adjacency list representation of the graph
    void printGraph() const;

    // Remove a unidirectional edge from vertex u to v
    bool removeEdge(int src, int dest);

    // Remove a bidirectional edge between vertices u and v
    bool removeBiDirectionalEdge(int src, int dest);
   
  // Other member functions...
};

#endif

