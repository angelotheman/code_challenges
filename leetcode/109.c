/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * findMid - Finds the midpoint of the LinkedList
 *
 * @head: Head of the LinkedList
 *
 * Return: Mid point LinkedList Node
 */

struct ListNode*  findMid(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;
    
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL;

    return (slow);
}

/**
 * createNode - Creates the root node from the LinkedList node
 * 
 * @val: Data to store in the TreeNode
 *
 * Return: The created Tree node
 */

struct TreeNode* createNode(int val)
{
    struct TreeNode* new_node = malloc(sizeof(struct TreeNode));

    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

/**
 * sortedListToBST - Sorts the List to BST
 *
 * @head: Pointer to the head of the list
 *
 * Return: The root of the built Binary Search Tree
 */

struct TreeNode* sortedListToBST(struct ListNode* head) {
    struct ListNode* mid;
    struct TreeNode* root;

    if (!head)
        return (NULL);

    if (!head->next)
        return (createNode(head->val));
    
    mid = findMid(head);
    root = createNode(mid->val);

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);

    return (root);
}
