/*
104. Maximum Depth of Binary Tree
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
#include <iostream>
#include <algorithm>
#include <cstddef> // Include the necessary header for NULL

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // Function to calculate the maximum depth of a binary tree
    int maxDepth(TreeNode *root)
    {
        // Check if the root is NULL (empty tree)
        if (root == NULL)
            return 0;

        // Recursively calculate the maximum depth of the left and right subtrees
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        // The maximum height of the current subtree is the maximum of the left and right subtree heights plus 1 (for the current level)
        int maxHeight = 1 + std::max(leftHeight, rightHeight);

        return maxHeight;
    }
};

int main()
{
    // Create a binary tree for testing (you can modify this structure for your own test cases)
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;

    int depth = solution.maxDepth(root);

    std::cout << "Maximum Depth of the Binary Tree: " << depth << std::endl;

    return 0;
}

/*
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2

Constraints:

The number of nodes in the tree is in the range [0, 10^4].
-100 <= Node.val <= 100
*/