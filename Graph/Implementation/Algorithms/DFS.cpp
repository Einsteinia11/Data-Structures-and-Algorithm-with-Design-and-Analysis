/***************************************************
 *        Implementation file for DFS.cpp          *
 *                                                 *
 *    Performs DFS on both Weighted and UnWeighted *
 *                    Graphs                       *
 *                                                 *
 *         author - Prabhat-Kumar-42               *
 *  github - https://github.com/Prabhat-Kumar-42   *
 *                                                 *
 ***************************************************/

#include "../../Header/Algorithms/DFS.h"
#include "../../Header/Graph/Graph.h"
#include "../../Header/Graph/WeightedGraph.h"
#include <stack>
#include <vector>

// Constructor for Graph
DFS::DFS(const Graph &graph) : graph(&graph), weightedGraph(nullptr) {
  unweightedGraphAdjList = graph.getAdjList();
}

// Constructor for WeightedGraph
DFS::DFS(const WeightedGraph &graph) : graph(nullptr), weightedGraph(&graph) {
  weightedGraphAdjList = graph.getAdjList();
}

// Perform DFS traversal starting from a specific vertex
std::vector<int> DFS::traverseRecursive(int startVertex) {
  visited.clear();
  dfsList.clear();
  if (graph) {
    dfsRecursiveUnWeightedGraph(startVertex);
  } else if (weightedGraph) {
    dfsRecursiveWeightedGraph(startVertex);
  }
  return dfsList;
}

// Perform DFS traversal starting from a specific vertex
std::vector<int> DFS::traverseNonRecursive(int startVertex) {
  visited.clear();
  dfsList.clear();
  if (graph) {
    dfsNonRecursiveUnWeightedGraph(startVertex);
  } else if (weightedGraph) {
    dfsNonRecursiveWeightedGraph(startVertex);
  }
  return dfsList;
}

// Recursive function for DFS traversal for Graph
void DFS::dfsRecursiveUnWeightedGraph(int vertex) {
  visited.insert(vertex);
  dfsList.push_back(vertex);
  for (int neighbor : unweightedGraphAdjList[vertex]) {
    if (visited.find(neighbor) == visited.end()) {
      dfsRecursiveUnWeightedGraph(neighbor);
    }
  }
}

// Recursive function for DFS traversal for WeightedGraph
void DFS::dfsRecursiveWeightedGraph(int vertex) {
  visited.insert(vertex);
  dfsList.push_back(vertex);
  for (auto neighbor : weightedGraphAdjList[vertex]) {
    if (visited.find(neighbor.first) == visited.end()) {
      dfsRecursiveWeightedGraph(neighbor.first);
    }
  }
}

// Non-recursive DFS traversal for Graph
void DFS::dfsNonRecursiveUnWeightedGraph(int startVertex) {
  std::stack<int> stack;
  stack.push(startVertex);

  while (!stack.empty()) {
    int vertex = stack.top();
    stack.pop();

    if (visited.find(vertex) == visited.end()) {
      visited.insert(vertex);
      dfsList.push_back(vertex);

      // Push unvisited neighbors onto the stack
      for (int neighbor : unweightedGraphAdjList[vertex]) {
        if (visited.find(neighbor) == visited.end()) {
          stack.push(neighbor);
        }
      }
    }
  }
}

// Non-recursive DFS traversal for WeightedGraph
void DFS::dfsNonRecursiveWeightedGraph(int startVertex) {
  std::stack<int> stack;
  stack.push(startVertex);

  while (!stack.empty()) {
    int vertex = stack.top();
    stack.pop();

    if (visited.find(vertex) == visited.end()) {
      visited.insert(vertex);
      dfsList.push_back(vertex);

      // Push unvisited neighbors onto the stack
      for (auto neighbor : weightedGraphAdjList[vertex]) {
        if (visited.find(neighbor.first) == visited.end()) {
          stack.push(neighbor.first);
        }
      }
    }
  }
}
