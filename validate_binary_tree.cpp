class Solution {
public:
    bool isValidBST(TreeNode* root, long long minn = LONG_MIN, long long maxx = LONG_MAX) {
        if(!root){
            return true;
        }
        if(root->val <= minn or root->val >= maxx){
            return false;
        }
        return isValidBST(root->left, minn, root->val) and isValidBST(root->right, root->val, maxx);
    }
};