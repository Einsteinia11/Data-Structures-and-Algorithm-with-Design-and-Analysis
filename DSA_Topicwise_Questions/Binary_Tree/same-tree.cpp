/*
100. Same Tree
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/
#include <iostream>
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
    // Function to check if two binary trees are the same
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // If either p or q is NULL, they must both be NULL for the trees to be the same
        if (p == NULL || q == NULL)
        {
            return (p == q);
        }

        // Check if the current nodes have the same value and recursively check the left and right subtrees
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    // Create two binary trees for testing (you can modify this structure for your own test cases)
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution solution;

    if (solution.isSameTree(p, q))
        std::cout << "The two binary trees are the same." << std::endl;
    else
        std::cout << "The two binary trees are not the same." << std::endl;

    return 0;
}

/*
Example 1:

Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:

Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:

Input: p = [1,2,1], q = [1,1,2]
Output: false


Constraints:

The number of nodes in both trees is in the range [0, 100].
-10^4 <= Node.val <= 10^4

*/