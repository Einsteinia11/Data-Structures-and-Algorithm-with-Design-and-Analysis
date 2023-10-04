#include "../../Header/Graph/Graph.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

// Constructor to initialize the graph with 'vertices' number of vertices
Graph::Graph(int vertices) : V(vertices) {
    adjList.resize(V);
}

// Function to add a unidirectional edge from 'src' to 'dest'
bool Graph::addUniDirectionalEdge(int src, int dest) {
    // Check if 'src' and 'dest' are valid vertex indices
    if (src >= 0 && src < V && dest >= 0 && dest < V) {
        adjList[src].push_back(dest);
        return true;
    } else {
        return false;
    }
}

// Function to add a bidirectional edge between 'src' and 'dest'
bool Graph::addBiDirectionalEdge(int src, int dest) {
    try {
        // Attempt to add edges in both directions
        if (addUniDirectionalEdge(src, dest) && addUniDirectionalEdge(dest, src)) {
            return true;
        } else {
            throw std::runtime_error("Edge addition failed.");
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

// Function to check if an edge exists between 'src' and 'dest'
bool Graph::isEdge(int src, int dest) {
    // Check if 'src' and 'dest' are valid vertex indices
    if (src >= 0 && src < V && dest >= 0 && dest < V) {
        // Iterate through the adjacency list of 'src' to find 'dest'
        for (int neighbor : adjList[src]) {
            if (neighbor == dest) {
                return true; // Edge found
            }
        }
    }
    return false; // Edge not found
}

// Function to retrieve whether the graph is weighted or not
bool Graph::getIsWeighted() const {
    return isWeighted;
}

// Function to print the adjacency list representation of the graph
void Graph::printGraph() const {
    for (int i = 0; i < V; ++i) {
        std::cout << "Adjacency list for vertex " << i << ": ";
        for (int j : adjList[i]) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

// Remove a unidirectional edge from vertex u to v
bool Graph::removeEdge(int src, int dest) {
    try {
        // Check if an edge exists from u to v
        if (isEdge(src, dest)) {
            // Edge exist, remove edge 
             adjList[src].erase(std::remove(adjList[src].begin(), adjList[src].end(), dest), adjList[src].end());
        }
        // We can just return true if there's no edge between two vertexes as this
        // function is to remove edge between two   
        return true; // Edge removed successfully
    } catch (const std::out_of_range& e) {
        // Handle any out-of-range exception (e.g., u or v is not a valid vertex)
        return false; // Return false indicating failure
    }
}

// Remove a bidirectional edge between vertices u and v
bool Graph::removeBiDirectionalEdge(int src, int dest) {
    // Call removeEdge for both directions (u to v and v to u)
    bool success1 = removeEdge(src, dest);
    bool success2 = removeEdge(dest, src);

    // Return true if both edges were successfully removed, false otherwise
    return success1 && success2;
}
