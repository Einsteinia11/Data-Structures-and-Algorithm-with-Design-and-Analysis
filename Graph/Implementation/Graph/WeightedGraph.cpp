#include "../../Header/Graph/WeightedGraph.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

// Constructor to initialize the weighted graph
WeightedGraph::WeightedGraph() {
    // No need to initialize anything here since it's an empty graph initially
}

// Function to add a unidirectional edge from 'src' to 'dest' with a given 'weight'
bool WeightedGraph::addUniDirectionalEdge(int src, int dest, int weight) {
    adjList[src].emplace_back(dest, weight);
    return true;
}

// Function to add a bidirectional edge between 'src' and 'dest' with a given 'weight'
bool WeightedGraph::addBiDirectionalEdge(int src, int dest, int weight) {
    try {
        // Attempt to add edges in both directions
        if (addUniDirectionalEdge(src, dest, weight) && addUniDirectionalEdge(dest, src, weight)) {
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
bool WeightedGraph::isEdge(int src, int dest) {
    const auto it = adjList.find(src);
    if (it != adjList.end()) {
        // Iterate through the adjacency list of 'src' to find 'dest'
        for (const std::pair<int, int>& edge : it->second) {
            if (edge.first == dest) {
                return true; // Edge found
            }
        }
    }
    return false; // Edge not found
}

// Function to retrieve whether the graph is weighted or not
bool WeightedGraph::getIsWeighted() const {
    return isWeighted;
}

// Function to print the adjacency list representation of the graph
void WeightedGraph::printGraph() const {
    for (const auto& entry : adjList) {
        std::cout << "Adjacency list for vertex " << entry.first << ": ";
        for (const std::pair<int, int>& edge : entry.second) {
            std::cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        std::cout << std::endl;
    }
}

// Function to add a vertex to the graph
bool WeightedGraph::addVertex(int vertex) {
    if (adjList.find(vertex) == adjList.end()) {
        adjList[vertex] = {};
        return true;
    }
    return false;
}

// Function to remove a vertex from the graph
bool WeightedGraph::removeVertex(int vertex) {
    auto it = adjList.find(vertex);
    if (it != adjList.end()) {
        adjList.erase(it);
        // Remove all edges that connect to the removed vertex
        for (auto& entry : adjList) {
            entry.second.erase(
                std::remove_if(entry.second.begin(), entry.second.end(),
                    [vertex](const std::pair<int, int>& edge) {
                        return edge.first == vertex;
                    }
                ),
                entry.second.end()
            );
        }
        return true;
    }
    return false;
}

// Function to get the number of vertices in the graph
int WeightedGraph::getVertexCount() const {
    return adjList.size()+1;
}

// Function to get a vector of vertices in the graph
std::vector<int> WeightedGraph::getVertices() const {
    std::vector<int> vertices;
    for (const auto& entry : adjList) {
        vertices.push_back(entry.first);
    }
    return vertices;
}

// Remove a unidirectional edge from vertex u to v
bool WeightedGraph::removeEdge(int src, int dest) {
    auto it = adjList.find(src);
    if (it != adjList.end()) {
        auto& edges = it->second;
        auto edgeToRemove = std::remove_if(edges.begin(), edges.end(),
            [dest](const std::pair<int, int>& edge) {
                return edge.first == dest;
            }
        );
        if (edgeToRemove != edges.end()) {
            edges.erase(edgeToRemove, edges.end());
            return true;
        }
    }
    return false;
}

// Remove a bidirectional edge between vertices u and v
bool WeightedGraph::removeBiDirectionalEdge(int src, int dest) {
    bool success1 = removeEdge(src, dest);
    bool success2 = removeEdge(dest, src);
    return success1 && success2;
}
// Function to check if a vertex exists in the graph
bool WeightedGraph::hasVertex(int vertex) {
    return adjList.find(vertex) != adjList.end();
}

// Function to get the weight of the edge between 'src' and 'dest'
int WeightedGraph::getEdgeWeight(int src, int dest) {
    // Check if 'src' and 'dest' are valid vertex indices
    if (src >= 0 && src < getVertexCount() && dest >= 0 && dest < getVertexCount()) {
        // Iterate through the adjacency list of 'src' to find 'dest' and its weight
        for (const std::pair<int, int>& edge : adjList[src]) {
            if (edge.first == dest) {
                return edge.second; // Return the weight of the edge
            }
        }
    }
    // Return a sentinel value (e.g., -1) to indicate that the edge does not exist
    return -1;
}
