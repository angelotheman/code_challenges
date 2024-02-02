/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b)
{
    return ((a > b) ? a : b);
}

int height(struct TreeNode* root, int* diameter)
{
    int left_height, right_height;
    if (!root)
        return (0);
    
    left_height = height(root->left, diameter);
    right_height = height(root->right, diameter);

    *diameter = max(*diameter, left_height + right_height);
    return (max(left_height, right_height) + 1);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;

    height(root, &diameter);

    return (diameter);
}
