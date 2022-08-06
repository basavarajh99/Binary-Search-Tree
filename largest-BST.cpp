//Brute: using validate BST and countng no. of nodes in valid bst
//better: using postorder TC: O(N) SC: O(1)

class Nodeval 
{
  public:
  int minnode, maxnode, maxsize;
  Nodeval(int minnode, int maxnode, int maxsize)
  {
      this->minnode = minnode;
      this->maxnode = maxnode;
      this->maxsize = maxsize;
  }
};

class Solution
{
  private: 
    Nodeval largestbst(Node* root) //postorder
    {
      if(!root) return Nodeval(INT_MAX, INT_MIN, 0);
      
      //left and right subtree of current tree
      auto left = largestbst(root->left);
      auto right = largetsbst(root->right);
      
      //current node is > max of left and < min of right. then its a valid bst
      if(left.maxnode < root->val and right.minnode > root->val)
        return Nodeval(min(root->val, left.minnode), max(root->val, right.maxnode), left.maxsize+right.maxsize+1); //in case null val, so min(), max()
      
      //Not a valid BST
      return Nodeval(INT_MIN, INT_MAX, max(left.maxsize, right.maxsize));
    }
  
  public:
  int largetsBSTsubtree(TreeNode* root)
  {
    return largestbst(root).maxsize;
  }
}
