//true if there exists 2 numbers else false even if one number = target
//use BSTIterator TC: O(N) SC: O(H)

class BSTIterator 
{
  //reverse = true : before
  //reverse = false : after
  bool reverse = true;
  private: stack<Node*> st;
  public: 
  BSTIterator(Node* root, bool isreverse)
  {
    reverse = isreverse;
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
    if(reverse) pushAll(topnode->right);
    else pushAll(topnode->right);
    return topnode->val;
  }
  
  private:
  void pushAll(Node* node)
  {
    for(; node!=NULL;)
    {
      st.push(node);
      if(reverse) node = node->right;
      else node = node->left;
    }
  }
  
};

class solution
{
  public:
  bool findtarget(Node* root, int k)
  {
    if(!root) return false;
    BSTIterator l(root, false); //next
    BSTIterator r(root, true); //before
    
    int i = l.next();
    int j = r.next();
    
    while(i<j)
    {
      if(i+j == k) return true;
      else if(i+j < k) i = l.next();
      else j = r.next();
    }
    
    return false;
  }
};
