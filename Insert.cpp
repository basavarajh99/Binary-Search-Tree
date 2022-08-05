//multiple possibilities

Node* insert(Node* root, int val)
{
  if(!root) return new Node(val);
  
  Node* cur = root;
  
  while(true)
  {
    if(cur->val <= val)
    {
      if(cur->right) cur = cur->right;
      else 
      {
        cur->right = new Node(val);
        break;
      }
    }
    else
    {
      if(cur->left) cur = cur->left;
      else
      {
        cur->left = new Node(val);
        break;
      }
    }
  }
  
  return root;
}
