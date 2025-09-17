class Solution {
private: 
    void helper(int n, string st,vector<string> &ans) {
        if(st.length() == n) {
            ans.push_back(st);
            return;
        }
        if(st[0] == '0'){
            helper(n, "1"+st, ans);
        }else{
            helper(n,"0"+st,ans);
            helper(n,"1"+st,ans);
            return;
        }

    } 
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        helper(n, "0", ans);
        helper(n, "1", ans);
        return ans;
    }
};