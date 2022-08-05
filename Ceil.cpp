//TC: O(logn)

int find(Node* root, int key)
{
  int ceil = -1;
  if(root->val == key) return root->val;
  
  else if (key > root->val) root = root->right;
  
  else 
  {
    ceil = root->data;
    root = root->left;
  }
  
  return ceil;
}
