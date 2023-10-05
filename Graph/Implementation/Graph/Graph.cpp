/***************************************************
 *      Implementation file for UnWeighted Graph   *
 *                                                 *
 *         author - Prabhat-Kumar-42              *
 *  github - https://github.com/Prabhat-Kumar-42   *
 *                                                 *
 ***************************************************/

#include "../../Header/Graph/Graph.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

// Constructor to create an empty graph
Graph::Graph() {
  // No need to initialize anything here, the unordered_map grows dynamically
}

// Function to add a unidirectional edge from 'src' to 'dest'
bool Graph::addUniDirectionalEdge(int src, int dest) {
  // Check if 'src' and 'dest' are valid vertex indices
  if (adjList.find(src) != adjList.end() &&
      adjList.find(dest) != adjList.end()) {
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
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return false;
  } catch (const std::runtime_error &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return false;
  }
}

// Function to check if an edge exists between 'src' and 'dest'
bool Graph::isEdge(int src, int dest) {
  // Check if 'src' and 'dest' are valid vertex indices
  if (adjList.find(src) != adjList.end() &&
      adjList.find(dest) != adjList.end()) {
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
bool Graph::getIsWeighted() const { return isWeighted; }

// Function to print the adjacency list representation of the graph
void Graph::printGraph() const {
  for (const auto &entry : adjList) {
    int vertex = entry.first;
    const std::vector<int> &neighbors = entry.second;
    std::cout << "Adjacency list for vertex " << vertex << ": ";
    for (int neighbor : neighbors) {
      std::cout << neighbor << " ";
    }
    std::cout << std::endl;
  }
}

// Remove a unidirectional edge from vertex u to v
bool Graph::removeEdge(int src, int dest) {
  try {
    // Check if an edge exists from u to v
    if (isEdge(src, dest)) {
      // Edge exists, remove edge
      auto &neighbors = adjList[src];
      neighbors.erase(std::remove(neighbors.begin(), neighbors.end(), dest),
                      neighbors.end());
    }
    // We can just return true if there's no edge between two vertexes as this
    // function is to remove an edge between two
    return true; // Edge removed successfully
  } catch (const std::out_of_range &e) {
    // Handle any out-of-range exception (e.g., src or dest is not a valid
    // vertex)
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

// Function to add a vertex to the graph
bool Graph::addVertex(int vertex) {
  if (adjList.find(vertex) == adjList.end()) {
    adjList[vertex] =
        {}; // Initialize an empty list of neighbors for the new vertex
    return true;
  } else {
    return false; // Vertex already exists
  }
}

// Function to remove a vertex from the graph
bool Graph::removeVertex(int vertex) {
  // Check if the vertex exists in the graph
  if (adjList.find(vertex) != adjList.end()) {
    // Remove all edges connected to the vertex
    adjList.erase(vertex);

    // Remove references to the vertex in other vertices' adjacency lists
    for (auto &entry : adjList) {
      entry.second.erase(
          std::remove(entry.second.begin(), entry.second.end(), vertex),
          entry.second.end());
    }

    return true; // Vertex removed successfully
  } else {
    return false; // Vertex not found in the graph
  }
}

// Function to get the number of vertices in the graph
int Graph::getVertexCount() const { return adjList.size(); }

// Function to get a vector of all vertices in the graph
std::vector<int> Graph::getVertices() const {
  std::vector<int> vertices;
  for (const auto &entry : adjList) {
    vertices.push_back(entry.first);
  }
  return vertices;
}

// Function to check if a vertex exists in the graph
bool Graph::hasVertex(int vertex) {
  return adjList.find(vertex) != adjList.end();
}
