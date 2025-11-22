class Solution {
private:
    int helper(int idx, string &s, vector<string>& dict, vector<int>& dp){
        //base case
        if(idx==s.size()) return 1;
        if(dp[idx]!=-1) return dp[idx];
        for(string str: dict){
            int len = str.length();
            if(idx+len<=s.size() && s.substr(idx, len)==str){
                if(helper(idx+len,s,dict,dp)==1) return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return helper(0, s, wordDict, dp);
    }
};