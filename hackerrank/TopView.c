/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
void topView( struct node *root) {
    if (!root)
        return;
        
    printf("%d ", root->data);
    topView(root->right);
}
