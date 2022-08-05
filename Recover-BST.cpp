//two nodes are swapped
//Brute: TC: O(2N)+O(NlogN) and SC: O(N)
//Better: inorder with modification TC: O(N) SC: O(1)

class Solve
{
  private: 
      Node* first;
      Node* prev;
      Node* middle;
      Node* last;
      
      void inorder(Node* root)
      {
        if(!root) return;
        
        inorder(root->left);
        
        if(prev and (root->val < prev->val))
        {
          //If this is first voilation, then mark these nodes as first and middle
          
          if(!first)
          {
            first = prev;
            middle = root;
          }
          //if this is second voilation, mark this as last
          else
            last = root;
        }
        //mark this node as previous
        prev = root;
        inorder(root->right);
      }
  
  public: 
      void recoverBST(Node* root)
      {
        first = middle = last = NULL;
        prev = new Node(INT_MIN);
        inorder(root);
        if(first and last) swap(first->val, last->val);
        else if(first and middle) swap(first->val, middle->val);
      }
};
