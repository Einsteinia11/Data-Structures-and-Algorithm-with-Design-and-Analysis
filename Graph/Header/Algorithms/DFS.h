#ifndef DFS_H
#define DFS_H

#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>
class Graph;
class WeightedGraph;

class DFS {
public:
    // Constructor to initialize DFS with a graph
    DFS(const Graph& graph);
    DFS(const WeightedGraph& graph);

    // Perform DFS traversal starting from a specific vertex
    std::vector<int> traverseRecursive(int startVertex);
    std::vector<int> traverseNonRecursive(int startVertex);

private:
    const Graph* graph;
    const WeightedGraph* weightedGraph;
    std::unordered_set<int> visited;
    std::vector<int> dfsList;
    std::unordered_map<int, std::vector<int>> unweightedGraphAdjList;
    std::unordered_map<int, std::vector<std::pair<int, int>>> weightedGraphAdjList;
    // Recursive function for DFS traversal
    void dfsRecursiveUnWeightedGraph(int vertex);
    void dfsRecursiveWeightedGraph(int vertex);
    // Non-Recursive function for DFS traversal  
    void dfsNonRecursiveUnWeightedGraph(int vertex);
    void dfsNonRecursiveWeightedGraph(int vertex);
};

#endif
