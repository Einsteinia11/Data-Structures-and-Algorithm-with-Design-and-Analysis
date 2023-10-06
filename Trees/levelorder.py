#CLASS FOR INDIVIDUAL NODE IN A TREE  
class Node():
    def __init__(self,key):
        self.data = key
        self.right = None
        self.left = None
        
#Function for level order traversal of nodes using queue
def levelorder(node):
    #Base case
    if node is None:
        return 
    
    #Creating a queue an adding node
    queue = []
    queue.append(node)
    
    while queue:
        #Popping the first node which is in the queue
        temp = queue.pop(0)
        print(temp.data, end = " ")
        
        #Adding left node of the queue
        if temp.left:
            queue.append(temp.left)
        
        #Adding right node of the queue
        if temp.right:
            queue.append(temp.right)
        
        
#Declare Tree
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("Preorder traversal of binary tree is")
print(levelorder(root))
# print(levelorder2(root))