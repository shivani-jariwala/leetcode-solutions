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
    vector<int> rightSideView(TreeNode* root) {
        //level-order
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int qSize = q.size();
            ans.push_back(q.front()->val);
            for(int i=0; i<qSize; i++) {
                TreeNode* first = q.front();
                q.pop();
                if(first->right!=NULL) q.push(first->right);
                if(first->left!=NULL) q.push(first->left); 
            }
        }
        return ans;
    }
};