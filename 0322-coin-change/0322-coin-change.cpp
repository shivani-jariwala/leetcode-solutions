class Solution {
    int helper(int idx, vector<int>& arr, int target, vector<vector<int>>&dp){
        if(target==0) return 0;
        if(idx==0) {
            if(target%arr[idx]==0) return target/arr[idx];
            else return 1e9;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int notPick = 0 + helper(idx-1, arr, target, dp);
        int pick = 1e9;
        if(arr[idx]<=target) pick = 1+helper(idx, arr, target-arr[idx], dp);
        dp[idx][target]=min(notPick, pick);
        return min(notPick, pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        if(helper(n-1, coins, amount, dp)>=1e9) {
            return -1;
        }
        return helper(n-1, coins, amount, dp);
    }
};