class Solution {
private:
    bool helper(int idx, vector<int>& arr, int target, vector<vector<int>>& dp) {
        if(target==0) return true;
        if(idx==0) return (arr[0]==target);
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool pick = false;
        if(arr[idx]<=target){
            pick = helper(idx-1,arr,target-arr[idx],dp);
        }
        bool notPick = helper(idx-1,arr,target,dp);
        dp[idx][target] = pick || notPick;
        return pick || notPick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0; i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false; //basically sum is odd then it can't be partioned
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return helper(n-1, nums, target, dp);
    }
};