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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            if(node!=NULL){
                //keep going left and add to stack
                st.push(node);
                node=node->left;
            }else{
                //add root and then move right
                //when to exit?? if the stack becomes emopty here
                if(st.empty()) break;
                TreeNode* frist = st.top();
                st.pop();
                ans.push_back(frist->val);
                node=frist->right;
            }
        }
        return ans;
    }
};