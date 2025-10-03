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
class Solution {
private:
    bool validateBST(TreeNode* root, long minVal, long maxVal){
        if(root==NULL) return true;
        if(root->val<=minVal || root->val>=maxVal) return false;
        bool lh = validateBST(root->left, minVal, root->val);
        bool rh = validateBST(root->right, root->val, maxVal);
        return lh&&rh; 
    }
public:
    bool isValidBST(TreeNode* root) {
        return validateBST(root, LONG_MIN, LONG_MAX);
    }
};