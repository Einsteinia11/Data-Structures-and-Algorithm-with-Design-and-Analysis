#CLASS FOR INDIVIDUAL NODE IN A TREE  
class Node():
    def __init__(self,key):
        self.data = key
        self.right = None
        self.left = None

#Function to do inorder tree traversal - Type 1 - return type list
def inorder(node):
    if node is None:
        return []
    return inorder(node.left) + [node.data] + inorder(node.right)

##Function to do inorder tree traversal - Type 2 -  return type string
def inorder2(node):
    if node:
        inorder2(node.left)
        print(node.data , end = " ")
        inorder2(node.right)

#Declare Tree
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("Inorder traversal of binary tree is")
print(inorder(root))
print(inorder2(root))
        