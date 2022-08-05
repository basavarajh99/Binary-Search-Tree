//for every node we will give a range [low, high] where it should lie
//initial = [INT_MIN, INT_MAX]
//TC: O(N) and SC: O(1)

bool isBST(Node* root, int low, int high)
{
  if(!root) return false;
  
  if(root->val <= low or root->val>=high) return false;
  
  return isBST(root->left, low, root->val) and isBST(root->right, root->val, high);
}

bool isvalid(Node* root)
{
  return isBST(root, INT_MIN, INT_MAX);
}
