//TC: O(H) and SC: O(1)

Node* inordersuccessor(Node* root, Node* p)
{
  Node* sucessor = NULL;
  
  while(root)
  {
    if(p->val >= root->val)
      root = root->right;
    else
    {
      successor = root;
      root = root->left;
    }
  }
  
  return successor;
}
