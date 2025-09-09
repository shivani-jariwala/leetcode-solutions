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
    TreeNode* helper(TreeNode* node) {
        if(node->left == NULL) return node->right;
        if(node->right == NULL) return node->left;
        TreeNode* ans = traversalFunc(node->right);
        ans->left = node->left;
        return node->right;

    }
    TreeNode* traversalFunc(TreeNode* node) {
        TreeNode* curr = node;
        while(node->left!=NULL) {
            node = node->left;
        }
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return {};
        if(root->val == key) {
            return helper(root);
        }
        if(root->val > key){
            //left
            root->left = deleteNode(root->left, key);
            return root;
        }else {
            root->right = deleteNode(root->right, key);
            return root;
        }
    };
};