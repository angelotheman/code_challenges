/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * createNode - Function to create the root node of the BST
 * @val: Data contained in the node
 *
 * Return: The node created or NULL if malloc failed
 */

struct TreeNode* createNode (int val)
{
    struct TreeNode* new_node = malloc(sizeof(struct TreeNode));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

/**
 * createTree - Function to create the Tree
 * @nums: Array pointing to the first integer
 * @start: Starting index
 * @end: End index
 *
 * Return: A created tree from the sorted Array
 */

struct TreeNode* createTree(int *nums, int start, int end)
{
    struct TreeNode* new_node;
    int mid = 0;

    if (start > end)
        return (NULL);
    
    mid = (start + end) / 2;
    new_node = createNode(nums[mid]);

    new_node->left = createTree(nums, start, mid - 1);
    new_node->right = createTree(nums, mid + 1, end);

    return (new_node);
}


/**
 * sortedArrayToBST - Main function to sort array to BST
 *
 * @nums: Pointer to the first integer in the array
 * @numsSize: The size of the array
 *
 * Return: A sorted array
 */

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (!nums || numsSize == 0)
        return (NULL);

    return createTree(nums, 0, numsSize - 1);    
}
