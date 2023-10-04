/*
110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced
A binary tree is considered balanced if, for every node in the tree, the heights of its left and right subtrees differ by at most one. This condition applies recursively to all nodes in the tree.
.
*/
#include <iostream>
#include <cstdlib>

// Definition of a TreeNode
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBalanced(TreeNode *root)
{
    return dfsheight(root) != -1; // Call dfsheight and check if it returns a valid height (-1 means unbalanced)
}

// Function to calculate the height of a binary tree using depth-first search
int dfsheight(TreeNode *root)
{
    if (root == NULL)
    {
        return 0; // Base case: An empty tree has a height of 0
    }

    int lh = dfsheight(root->left); // Calculate the height of the left subtree
    if (lh == -1)
    {
        return -1; // If the left subtree is unbalanced, propagate -1
    }

    int rh = dfsheight(root->right); // Calculate the height of the right subtree
    if (rh == -1)
    {
        return -1; // If the right subtree is unbalanced, propagate -1
    }

    if (abs(lh - rh) > 1)
    {
        return -1; // If the height difference between left and right subtrees is greater than 1, propagate -1
    }

    return std::max(lh, rh) + 1; // Return the height of the current subtree (adding 1 for the current node)
}

int main()
{
    // Create a sample balanced binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Call the isBalanced function to check if the tree is balanced
    bool balanced = isBalanced(root);

    // Print the result
    if (balanced)
    {
        std::cout << "The binary tree is balanced." << std::endl;
    }
    else
    {
        std::cout << "The binary tree is not balanced." << std::endl;
    }

    return 0;
}
