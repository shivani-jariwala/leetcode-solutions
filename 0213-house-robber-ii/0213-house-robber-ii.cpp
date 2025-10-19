class Solution {
private:
    int helper(int i, vector<int>& arr, vector<vector<int>>& dp, bool isLastElePicked) {
        if(i==0) {
            if(isLastElePicked) return 0;
            return arr[0];
        }
        if(i<0) return 0; 
        if(dp[i][isLastElePicked]!=-1) return dp[i][isLastElePicked];
        if(i == arr.size()-1) isLastElePicked = true;
        int pick = arr[i] + helper(i-2, arr, dp, isLastElePicked);
        if(i == arr.size()-1) isLastElePicked = false;
        int noPick = 0 + helper(i-1, arr, dp, isLastElePicked);
        return dp[i][isLastElePicked] = max(pick, noPick);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<vector<int>> dp(nums.size()+1, vector<int>(2, -1));
        return helper(nums.size()-1, nums, dp, false);
    }
};