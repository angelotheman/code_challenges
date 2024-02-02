/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/

int getHeight(struct node *root);
void traverse_level(struct node *root, int level);

void levelOrder( struct node *root) {
    int height = getHeight(root);
    
    if (!root)
        return;
    
    for (int i = 0; i <= height; i++)
    {
        traverse_level(root, i);
    }
}

/**
 * getHeight - Get's the height of the tree
 * @root: The root node of the tree
 *
 * Return: Height of the tree
 */

int getHeight(struct node *root)
{
    int left = 0;
    int right = 0;
    
    if (!root)
        return (0);
    
    left = root->left ? 1 + getHeight(root->left) : 0;
    right = root->right ? 1 + getHeight(root->right) : 0;
    
    return ((left > right) ? left : right);
}

/**
 * traverse_level - Helper function to traverse the tree
 * @root: The node at which to traverse
 * @level: The level or height at which the traversal is being done
 */

void traverse_level(struct node *root, int level)
{
    if (!root)
        return;
    
    if (level == 0)
        printf("%d ", root->data);
    
    traverse_level(root->left, level - 1);
    traverse_level(root->right, level - 1);
}
