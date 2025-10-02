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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        TreeNode* curr=root;
        q.push(curr);
        while(!q.empty()) {
            vector<int> level;
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* first = q.front();
                q.pop();
                level.push_back(first->val);
                if(first->left!=NULL) q.push(first->left);
                if(first->right!=NULL) q.push(first->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};