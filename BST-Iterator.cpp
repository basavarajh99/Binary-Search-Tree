//next: should return next node in tree
//hasnext: should return true or false
//not allowed to store inorder traversal
//TC: O(1) SC:O(H)
//uses stack

class BSTIterator 
{
  private: stack<Node*> st;
  public: 
  BSTIterator(Node* root)
  {
    pushAll(root);
  }
  
  bool hasnext()
  {
    return !st.empty();
  }
  
  int next()
  {
    Node* topnode = st.top();
    st.pop();
    pushAll(topnode->right);
    return topnode->val;
  }
  
  private:
  void pushAll(Node* node)
  {
    for(; node!=NULL; st.push(node), node = node->left);
  }
  
};
