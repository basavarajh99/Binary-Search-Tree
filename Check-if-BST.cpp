//for every node we will give a range [low, high] where it should lie
//initial = [INT_MIN, INT_MAX]
//TC: O(N) and SC: O(1)

 bool isBST(TreeNode* root, long high, long low)
{
    if(!root) return true;

    if(root->val <= low or root->val >= high) return false;

    return isBST(root->left, root->val, low) and isBST(root->right, high, root->val);
}

bool isValidBST(TreeNode* root) {
    return isBST(root, (1LL<<31), -(1LL<<31)-1);
}
