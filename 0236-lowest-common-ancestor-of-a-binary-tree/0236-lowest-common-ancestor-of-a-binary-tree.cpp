/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private: 
    TreeNode* computeLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return root;
        if(root==p || root==q) return root;
        TreeNode* lcaH = computeLCA(root->left, p, q);
        TreeNode* lcaR = computeLCA(root->right, p, q);
        if(lcaH == NULL) return lcaR;
        if(lcaR == NULL) return lcaH;
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //concept of NULL
        return computeLCA(root, p, q);
    }
};