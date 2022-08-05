//Inorder of BST is always sorted
//morris-traversal
// kth largest = N-kth smallest

Node* kthsmallest(Node* root, int k)
{
  if(!root) return NULL;
  
  Node* left = kthsmallest(root->left, k); //for kth largest change to  Node* right = kthlargest(root->right, k); 
  if(left) return left; // change to right
  
  k--;
  
  if(k==0) return root;
  
  return kthsmallest(root->right, k); // change to left
}
