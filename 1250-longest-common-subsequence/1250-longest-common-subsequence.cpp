class Solution {
public:
    int helper(int idx1, int idx2, string &text1, string &text2, vector<vector<int>>&dp) {
        //base case
        if(idx1<0 || idx2<0) return 0; 
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(text1[idx1]==text2[idx2]) {
            dp[idx1][idx2] = 1 + helper(idx1-1, idx2-1, text1, text2, dp);
            return dp[idx1][idx2];
        }
        dp[idx1][idx2] = max(helper(idx1-1, idx2, text1, text2, dp),helper(idx1, idx2-1, text1, text2, dp));
        return dp[idx1][idx2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(n-1,m-1,text1, text2, dp);
    }
};