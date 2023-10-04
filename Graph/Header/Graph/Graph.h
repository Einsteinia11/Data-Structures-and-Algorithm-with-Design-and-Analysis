#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
private:
    int V; // Number of vertices
    const bool isWeighted = false; // Immutable flag to indicate if the graph is weighted
    std::vector<std::vector<int>> adjList; // Adjacency list

public:
    // Constructor to create a graph with 'vertices' number of vertices
    Graph(int vertices);

    // Function to add a unidirectional edge from 'src' to 'dest'
    bool addUniDirectionalEdge(int src, int dest);

    // Function to add a bidirectional edge between 'src' and 'dest'
    bool addBiDirectionalEdge(int src, int dest);

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

