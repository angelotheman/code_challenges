/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
struct node *lca( struct node *root, int v1, int v2 ) {
    if (!root)
        return (NULL);
        
    if (root->data == v1 || root->data == v2)
    {
        return (root);
    }
    else if ((v1 < root->data && v2 > root->data) || (v1 > root->data && v2 < root->data))
    {
        return (root);
    }
    else if (v1 < root->data && v2 < root->data)
    {
        lca(root->left, v1, v2);
    }
    else if (v1 > root->data && v2 > root->data)
    {
        lca(root->right, v1, v2);
    }
    
    return (root);
}
