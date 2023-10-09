#CLASS FOR INDIVIDUAL NODE IN A TREE  
class Node():
    def __init__(self,key):
        self.data = key
        self.right = None
        self.left = None

#Function to do preorder tree traversal - Type 1 - return type list
def preorder(node):
    if node is None:
        return []
    return  [node.data] + preorder(node.left) + preorder(node.right)

##Function to do preorder tree traversal - Type 2 - return type string
def preorder2(node):
    if node:
        print(node.data , end = " ")
        preorder2(node.left)
        preorder2(node.right)

#Declare Tree
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("Preorder traversal of binary tree is")
print(preorder(root))
print(preorder2(root))