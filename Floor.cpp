 //TC: O(logn)

int find(Node* root, int key)
{
  int floor = -1;
  if(root->val == key) return root->val;
  
  else if (key > root->val)
  {
    floor = root->data;
    root = root->right;
  }
  
  else 
    root = root->left;
  
  return floor;
}
