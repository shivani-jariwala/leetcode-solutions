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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    void recoverBST(TreeNode* root){
        if(root==NULL) return;
        recoverBST(root->left);
        if(prev!=NULL && (root->val < prev->val)){
            if(first==NULL){
                first = prev;
                middle = root;
            }else{
                last = root;
            }
        }
        prev=root;
        recoverBST(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        //take inorder since it gives us sorted array
        first = NULL, middle=NULL, last=NULL;
        prev = new TreeNode(INT_MIN);
        recoverBST(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};