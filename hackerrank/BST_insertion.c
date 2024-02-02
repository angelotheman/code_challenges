/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};
*/
struct node* createNode(int data);

struct node* insert( struct node* root, int data ) {
    if (!root)
    {
        struct node* new_node = createNode(data);
        root = new_node;
        return (root);
    }
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    
    return (root);
}

struct node* createNode(int data)
{
    struct node* new_node = malloc(sizeof(struct node));
        
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return (new_node);
}
