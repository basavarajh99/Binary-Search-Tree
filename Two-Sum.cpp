//true if there exists 2 numbers else false even if one number = target
//use BSTIterator TC: O(N) SC: O(H)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator{
public:

    stack<TreeNode*> st;
    bool reverse = true;
    
BSTIterator(TreeNode *root, bool isreverse){
    reverse = isreverse;
    pushAll(root);
}

bool hasnext()
{
    return !st.empty();
}
    
int next(){
    TreeNode *topNode = st.top();
    st.pop();
    if (!reverse) pushAll(topNode->right);
    else pushAll(topNode->left);

    return topNode->val;
}

private:
    void pushAll(TreeNode *node)
    {
        for(; node != NULL; )
        {
            st.push(node);
            if(reverse == true)
                node = node->right;
            else
                node = node->left;
        }
    }

};

class Solution {
public:
bool findTarget(TreeNode* root, int k) {
    if (root == NULL) return false;
    BSTIterator l(root, false);  //next
    BSTIterator r(root, true);  //before
    
    int i = l.next();
    int j = r.next();
    
    while (i < j){
        if (i + j == k) return true;
        else if (i + j < k) i = l.next();
        else j = r.next();
    }
    return false;
}
};

