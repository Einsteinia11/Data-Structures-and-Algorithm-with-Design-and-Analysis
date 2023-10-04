#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

class Graph {
private:
    const bool isWeighted = false; // Immutable flag to indicate if the graph is weighted
    std::unordered_map<int, std::vector<int>> adjList; // Adjacency list

public:
    // Constructor to create an empty graph
    Graph();

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

    // Function to add a vertex to the graph
    bool addVertex(int vertex);

    // Function to remove a vertex from the graph
    bool removeVertex(int vertex);

    // Function to get the number of vertices in the graph
    int getVertexCount() const;

    // Function to get a vector of all vertices in the graph
    std::vector<int> getVertices() const;

    // Function to check if a vertex exists in the graph
    bool hasVertex(int vertex);
};

#endif

