//given PREORDER
//Brute: O(N^2) constructing by picking one node at a time
//inorder is sorted: so sort given array TC: O(Nlogn)+O(N) and SC: O(N)
//simiilar to check if BST. just using upper bound is enough
// while calling left: upperbound = node->val and for right: upperbound= previous upperbound
//TC: O(N) SC: O(1)

Node* built(vector<int>& A, int i, int bound)
{
  if(i==A.size() || A[i] > bound) return NULL;
  
  Node* root = new Node(A[i++]);
  root->left = built(A, i, root->val); 
  root->right = built(A, i, bound);
  
  return root;
}

Node* construct(vector<int>& A)
{
  return built(A, 0, INT_MAX);
}
