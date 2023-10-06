public class AvlTree {
    // Inner class representing a node in the AVL tree
    public class Node {
        private int value;
        private int height;
        private Node left;
        private Node right;

        public Node(int value) {
            this.value = value;
        }

        public int getValue() {
            return value;
        }
    }

    private Node root;

    public AvlTree() {
        // Constructor for AVL Tree, initially, it's empty.
    }

    // Get the height of the tree
    public int height() {
        return height(root);
    }

    // Get the height of a specific node
    private int height(Node node) {
        if (node == null) {
            return -1;
        }
        return node.height;
    }

    // Check if the tree is empty
    public boolean isEmpty() {
        return root == null;
    }

    // Insert a value into the AVL tree
    public void insert(int value) {
        root = insert(value, root);
    }

    // Helper method for inserting a value into the AVL tree
    private Node insert(int value, Node node) {
        if (node == null) {
            node = new Node(value);
            return node;
        }

        if (value < node.value) {
            node.left = insert(value, node.left);
        } else if (value > node.value) {
            node.right = insert(value, node.right);
        }

        // Update the height of the current node
        node.height = Math.max(height(node.left), height(node.right)) + 1;

        // Perform rotation if necessary to maintain balance
        return rotate(node);
    }

    // Perform rotations to maintain balance in the AVL tree
    private Node rotate(Node node) {
        if (height(node.left) - height(node.right) > 1) {
            // Left-heavy
            if (height(node.left.left) - height(node.left.right) > 0) {
                // Left-left case
                return rightRotate(node);
            }
            if (height(node.left.left) - height(node.left.right) < 0) {
                // Left-right case
                node.left = leftRotate(node.left);
                return rightRotate(node);
            }
        }

        if (height(node.left) - height(node.right) < -1) {
            // Right-heavy
            if (height(node.right.left) - height(node.right.right) < 0) {
                // Right-right case
                return leftRotate(node);
            }
            if (height(node.right.left) - height(node.right.right) > 0) {
                // Right-left case
                node.right = rightRotate(node.right);
                return leftRotate(node);
            }
        }

        return node;
    }

    // Perform a right rotation
    public Node rightRotate(Node p) {
        Node c = p.left;
        Node t = c.right;
        c.right = p;
        p.left = t;
        p.height = Math.max(height(p.left), height(p.right) + 1);
        c.height = Math.max(height(c.left), height(c.right) + 1);
        return c;
    }

    // Perform a left rotation
    public Node leftRotate(Node c) {
        Node p = c.right;
        Node t = p.left;
        p.left = c;
        c.right = t;
        p.height = Math.max(height(p.left), height(p.right) + 1);
        c.height = Math.max(height(c.left), height(c.right) + 1);
        return p;
    }

    // Populate the AVL tree with an array of values
    public void populate(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            this.insert(nums[i]);
        }
    }

    // Populate the AVL tree with a sorted array of values
    public void populateSorted(int[] nums) {
        populateSorted(nums, 0, nums.length);
    }

    // Helper method to populate the AVL tree with a sorted array of values
    private void populateSorted(int[] nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = (start + end) / 2;
        this.insert(nums[mid]);
        populateSorted(nums, start, mid);
        populateSorted(nums, mid + 1, end);
    }

    // Check if the AVL tree is balanced
    public boolean balanced() {
        return balanced(root);
    }

    // Helper method to check if a specific node and its subtrees are balanced
    private boolean balanced(Node node) {
        if (node == null) {
            return true;
        }
        return Math.abs(height(node.left) - height(node.right)) <= 1 && balanced(node.left) && balanced(node.right);
    }

    // Display the AVL tree
    public void display() {
        display(this.root, "Root Node: ");
    }

    // Helper method to display the AVL tree
    private void display(Node node, String details) {
        if (node == null) {
            return;
        }
        System.out.println(details + node.value);
        display(node.left, "Left child of :" + node.value + " : ");
        display(node.right, "Right child of :" + node.value + " : ");
    }

    // Main method for testing
    public static void main(String[] args) {
        AvlTree tree = new AvlTree();
        for (int i = 0; i < 10000; i++) {
            tree.insert(i);
        }
        System.out.println(tree.height());
    }
}
