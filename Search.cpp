//left<root<right
//leftsubtree = BST = rightsubtree
//search = log(n)
//height = log(n)

Node* search(Node* root, int target)
{
   while(root and root->val!=target)
   root = (target < root->val) ? root->left : root->right;
   
   return root;
}
