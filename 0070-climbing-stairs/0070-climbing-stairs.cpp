class Solution {
private:
    int computeSteps(int n, vector<int> &dp){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]) return dp[n];
        int left = computeSteps(n-1, dp);
        int right = computeSteps(n-2, dp);
        int sum = left+right;
        dp[n] = sum;
        return sum;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        return computeSteps(n, dp);
    }
};