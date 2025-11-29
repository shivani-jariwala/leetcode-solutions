class Solution {
private:
    bool helper(int idx, string s, vector<string>& words, vector<int>& dp){
        //base case
        if(idx==s.length()) return true;
        if(dp[idx]!=-1) return dp[idx];
        //main logic
        for(string word: words) {
            int len = word.length();
            if(s.substr(idx, len) == word) {
                if(helper(idx+len, s, words, dp)) return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n =s.length();
        vector<int> dp(n, -1);
        return helper(0, s, wordDict, dp);
    }
};