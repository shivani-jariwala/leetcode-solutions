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
    int calHeight(TreeNode* root) {
        if(root==NULL) return 0;
        int lh = calHeight(root->left);
        int rh = calHeight(root->right);
        return 1+max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        //brute-force solution with O(N^2)
        if(root==NULL) return true;
        int lHeight= calHeight(root->left);
        int rHeight= calHeight(root->right);
        if(abs(lHeight-rHeight)>1) return false;
        bool isLeftBalanced = isBalanced(root->left);
        bool isRightBalanced = isBalanced(root->right);
        return isLeftBalanced && isRightBalanced;
    }

};