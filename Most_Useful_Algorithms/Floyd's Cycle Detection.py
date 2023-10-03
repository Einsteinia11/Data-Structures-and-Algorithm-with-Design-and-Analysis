class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

# initialize a head for the linked list
head = None

# defining a function to check if there exists a cycle
def CheckLoop(head):
	s = head
	f = head

	while (s != None and f != None and f.next != None):
		s = s.next
		f = f.next.next
		if (s == f):
			return 1

	return 0

# inserting new values
head = Node(5)
head.next = Node(10)
head.next.next = Node(20)
head.next.next.next = Node(40)
head.next.next.next.next = Node(80)

temp = head
while (temp.next != None):
	temp = temp.next

temp.next = head

if (CheckLoop(head)):
	print("Loop exists in the Linked List")
else:
	print("Loop does not exists in the Linked List")
