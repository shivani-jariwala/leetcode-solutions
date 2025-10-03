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
    int maxi=INT_MIN;
    int calculatePathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int leftHeight = max(0, calculatePathSum(root->left));
        int rightHeight = max(0, calculatePathSum(root->right));
        maxi = max(maxi, (root->val + leftHeight + rightHeight));
        return root->val + max(leftHeight, rightHeight);
    }
public:
    int maxPathSum(TreeNode* root) {
        calculatePathSum(root);
        return maxi;
    }
};