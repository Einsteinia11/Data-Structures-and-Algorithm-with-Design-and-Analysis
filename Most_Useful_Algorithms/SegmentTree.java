class SegmentTree {
    public static void main(String[] args) {
        int[] arr = {3, 8, 6, 7, -2, -8, 4, 9};
        SegmentTree tree = new SegmentTree(arr);
    }

    private static class Node {
        int data;
        int startInterval;
        int endInterval;
        Node left;
        Node right;

        public Node(int startInterval, int endInterval) {
            this.startInterval = startInterval;
            this.endInterval = endInterval;
        }
    }

    Node root;

    public SegmentTree(int[] arr) {
        // Create a tree using the arr
        this.root = constructTree(arr, 0, arr.length - 1);
    }

    private Node constructTree(int[] arr, int start, int end) {
        if (start == end) {
            // Leaf node
            Node leaf = new Node(start, end);
            leaf.data = arr[start];
            return leaf;
        }

        // Create a new node with the index you are at
        Node node = new Node(start, end);
        int mid = (start + end) / 2;

        node.left = this.constructTree(arr, start, mid);
        node.right = this.constructTree(arr, mid + 1, end);

        node.data = node.left.data + node.right.data;
        return node;
    }

    public void display() {
        display(this.root);
    }
    // To display the nodes
    private void display(Node node) {
        String str = "";
        if (node.left != null) {
            str = str + "Interval=[" + node.startInterval + "-" + node.endInterval + "] and data: " + node.left.data + " => ";
        } else {
            str = str + "No left child";
        }
        // For the current node
        str = str + "Interval=[" + node.startInterval + "-" + node.endInterval + "] and data: " + node.data + " <= ";

        if (node.right != null) {
            str = str + "Interval=[" + node.right.startInterval + "-" + node.right.endInterval + "] and data: " + node.right.data + " => ";
        } else {
            str = str + "No right child";
        }
        System.out.println(str);
        // Call recursion
        if (node.left != null) {
            display(node.left);
        }
        if (node.right != null) {
            display(node.right);
        }
    }

    // Query
    public int query(int qsi, int qei) {
        return this.query(this.root, qsi, qei);
    }

    private int query(Node node, int qsi, int qei) {
        if (node.startInterval >= qsi && node.endInterval <= qei) {
            // Node is completely lying inside the query
            return node.data;
        } else if (node.startInterval > qei || node.endInterval < qsi) {
            // Completely outside the query
            return 0;
        } else {
            return this.query(node.left, qsi, qei) + this.query(node.right, qsi, qei);
        }
    }

    // Update
    public void update(int index, int value) {
        if ((index >= node.startInterval) && (index <= node.endInterval)) {
            if (index == node.startInterval && index == node.endInterval) {
                node.data = value;
            } else {
                int leftAns = update(node.left, index, value);
                int rightAns = update(node.right, index, value);

                node.data = leftAns + rightAns;
            }
        }
    }
}
