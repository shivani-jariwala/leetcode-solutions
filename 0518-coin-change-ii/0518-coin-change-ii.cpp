class Solution {
public:
    int helper(int idx, vector<int>& arr, int target, vector<vector<int>>&dp){
        if(target==0) return 1;
        if(idx==0) {
            if(target%arr[idx]==0) return 1;
            else return 0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int notPick = helper(idx-1, arr, target, dp);
        int pick = 0;
        if(arr[idx]<=target) pick = helper(idx, arr, target-arr[idx], dp);
        dp[idx][target]=notPick+pick;
        return notPick+pick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return helper(n-1, coins, amount, dp);
    }
};