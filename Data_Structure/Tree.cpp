struct node
{
	int data;
	node* left;
	node* right;
};

void preOrder(node *root) {
    
    cout << root->data << " ";
    if(root->left != NULL)  preOrder(root->left);
    if(root->right != NULL) preOrder(root->right);
}

void postOrder(node *root) {
    
    if(root->left != NULL)  postOrder(root->left);
    if(root->right != NULL) postOrder(root->right);
    cout << root->data << " ";
}
void inOrder(node *root) {
    
    if(root->left != NULL) inOrder(root->left);
    cout << root->data << " ";
    if(root->right != NULL) inOrder(root->right);
}