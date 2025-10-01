class Solution {
private:
    int computeSteps(int n, vector<int>&dp){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int oneJump = computeSteps(n-1, dp);
        int twoJump = computeSteps(n-2, dp);
        dp[n] = oneJump+twoJump;
        return oneJump + twoJump;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return computeSteps(n, dp);
    }
};