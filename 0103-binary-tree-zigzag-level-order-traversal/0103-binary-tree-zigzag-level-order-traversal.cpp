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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //same as level order
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        TreeNode* curr=root;
        bool leftToRight = true;
        q.push(curr);
        while(!q.empty()) {
            int qSize = q.size();
            vector<int> level(qSize);
            for(int i=0; i<qSize; i++) {
                TreeNode* first = q.front();
                q.pop();
                int idx = leftToRight ? i : qSize - 1 - i;
                level[idx] = first->val;
                if(first->left!=NULL) q.push(first->left);
                if(first->right!=NULL) q.push(first->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
        return ans;
    }
};