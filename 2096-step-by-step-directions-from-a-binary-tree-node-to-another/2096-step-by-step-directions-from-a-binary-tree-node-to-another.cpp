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
    bool getPath(TreeNode* root, int value, string& path){
    if(!root) return false;
    if(root->val == value) return true;
    path.push_back('L');
    if(getPath(root->left, value, path)) return true;
    path.pop_back();

    path.push_back('R');
    if(getPath(root->right, value, path)) return true;
    path.pop_back();

    return false;
   }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;
    getPath(root, startValue, startPath);
    getPath(root, destValue, destPath);

    int i = 0;
    while(i<startPath.size() && i<destPath.size() && startPath[i]==destPath[i]) i++;

    string res = "";
    for(int j=i; j<startPath.size();j++){
      res +='U';
    }
    res += destPath.substr(i);
    return res;
    }
};