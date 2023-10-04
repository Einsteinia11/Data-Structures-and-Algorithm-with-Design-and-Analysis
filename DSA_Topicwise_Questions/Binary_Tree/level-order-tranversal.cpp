/*102. Binary Tree Level Order Traversal*/
/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).*/
#include <iostream>
#include <vector>
#include <queue>

// Definition of a TreeNode
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> ans;

    if (root == NULL)
    {
        return ans;
    }

    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        std::vector<int> levels;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front(); // Get the front node from the queue
            q.pop();                    // Remove the front node from the queue

            if (node->left != NULL)
            {
                q.push(node->left); // Push the left child into the queue if it exists
            }

            if (node->right != NULL)
            {
                q.push(node->right); // Push the right child into the queue if it exists
            }

            levels.push_back(node->val); // Add the value of the current node to the levels vector
        }

        ans.push_back(levels); // Add the levels vector to the result vector
    }

    return ans;
}

int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Call the levelOrder function to perform level order traversal
    std::vector<std::vector<int>> result = levelOrder(root);

    // Print the result
    for (const auto &level : result)
    {
        for (int val : level)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
