//point of split is lca
//TC: O(H) SC: O(1)

Node* lca(Node* root, Node* p, Node* q)
{
  if(!root) return NULL;
  
  int cur = root->val;
  
  if(cur > p->val and cur > q->val)
    return lca(root->left, p, q);
  
  if(cur < p->val and cur < q->val)
    return lca(root->right, p, q);
  
  return root;
}
