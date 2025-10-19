class Solution {
private:
    int helper(int i, vector<int>& arr, vector<int>& dp) {
        if(i == 0) return arr[i];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick = arr[i] + helper(i-2, arr, dp);
        int noPick = 0 + helper(i-1, arr, dp);
        dp[i] = max(pick, noPick);
        return max(pick, noPick);
    }
public:
    int rob(vector<int>& nums) {    
        vector<int> dp(nums.size()+1, -1);
        return helper(nums.size()-1, nums, dp);
    }
};