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
    bool isSame(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL) return p==q;
        return (p->val==q->val) && isSame(p->left, q->left) && isSame(p->right, q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(isSame(root, subRoot)) return true;
        bool lh = isSubtree(root->left, subRoot);
        bool rh = isSubtree(root->right, subRoot);
        return lh || rh;
    }
};