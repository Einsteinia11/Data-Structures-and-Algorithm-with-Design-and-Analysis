# importing defaultdictionary from collections
from collections import defaultdict

class Graphs:
    def __init__(self):
        self.graph = defaultdict(list)

    # defining a function which can add edge to the graph
    def addEdge(self,v1,v2):
        self.graph[v1].append(v2)

    # defining a function for the bfs traversal of the graph
    def bfs(self,node):
        visited = [] # creating a list to check whether a node is already visited or not
        q = []
        visited.append(node)
        q.append(node)

        while q:
            # popping the element which is to be printed
            node = q.pop(0)
            print(str(node)+" ",end="") # printing the bfs traversal of the graph

            # getting adjacent nodes of the node which is popped
            for v in self.graph[node]:
                if v not in visited:
                    q.append(v)
                    visited.append(v)

g = Graphs()
n = int(input("Enter number of edges: "))
for i in range(n):
    s,d = map(int,input().split())
    g.addEdge(s,d)

s = int(input("Enter source vertex: "))
print("BFS Traversal of the graph is:")
g.bfs(s)