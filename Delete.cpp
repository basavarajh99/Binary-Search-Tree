Node* find(Node* root)
{
  if(!root->right) return root;
  
 return find(root->right);
}

Node* helper(Node* root)
{
  if(!root->left) return root->right;
  
  else if(!root->right) return root->left;
  
  Node* rightchild = root->right;
  Node* lastright = find(root->left);
  lastright->right = rightchild;
  
  return root->left;
}

Node* delete(Node* root, int key)
{
  if(!root) return NULL;
  if(root->val == key) return helper(root);
  
  Node* dummy = root;
  
  while(root)
  {
    if(root->val > key)
    {
      if(root->left and root->left->val == key)
      {
        root->left = helper(root->left); 
        break;
      }
      
      else
        root = root->left;
    }
    
    else
    {
      if(root->right and root->right->val == key)
      {
        root->right = helper(root->right);
        break;
      }
      
      else
        root = root->right;
    }
  }
  
  return dummy;
}
