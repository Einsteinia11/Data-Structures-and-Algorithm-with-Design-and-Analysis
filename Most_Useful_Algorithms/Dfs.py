# importing defaultdictionary from collections
from collections import defaultdict

class Graphs:
    def __init__(self):
        self.graph = defaultdict(list)

    # defining a function which can add edge to the graph
    def addEdge(self,v1,v2):
        self.graph[v1].append(v2)

    # defining a recursive function for the dfs traversal of the graph
    def dfs(self,visited,node):
        if node not in visited:
            print(str(node)+" ",end="") # printing the dfs traversal of the graph
            visited.add(node) # adding visited vertices to a set

            # getting the adjacent nodes of the node
            for v in self.graph[node]:
                self.dfs(visited,v)


g = Graphs()
n = int(input("Enter number of edges: "))
for i in range(n):
    s,d = map(int,input().split())
    g.addEdge(s,d)
visited = set()
s = int(input("Enter source vertex: "))
print("DFS Traversal of the graph is:")
g.dfs(visited,s)