#CLASS FOR INDIVIDUAL NODE IN A TREE  
class Node():
    def __init__(self,key):
        self.data = key
        self.right = None
        self.left = None

#Function to do postorder tree traversal - Type 1 - return type list
def postorder(node):
    if node is None:
        return []
    return   postorder(node.left) + postorder(node.right) + [node.data] 

##Function to do postorder tree traversal - Type 2 - return type string
def postorder2(node):
    if node:
        postorder2(node.left)
        postorder2(node.right)
        print(node.data , end = " ")

#Declare Tree
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("Postorder traversal of binary tree is")
print(postorder(root))
print(postorder2(root))