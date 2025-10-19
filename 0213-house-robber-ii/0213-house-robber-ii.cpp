class Solution {
private:
    int helper(int i, vector<int>& arr, vector<int>& dp) {
        if(i==0) return arr[0];
        if(i<0) return 0; 
        if(dp[i]!=-1) return dp[i];
        int pick = arr[i] + helper(i-2, arr, dp);
        int noPick = 0 + helper(i-1, arr, dp);
        dp[i] = max(pick, noPick);
        return max(pick, noPick);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0; i<nums.size(); i++) {
            if(i!=nums.size()-1) temp1.push_back(nums[i]);
            if(i!=0) temp2.push_back(nums[i]);
        }
        vector<int> dp1(nums.size()+1, -1);
        vector<int> dp2(nums.size()+1, -1);
        return max(helper(temp1.size()-1, temp1, dp1), helper(temp2.size()-1, temp2, dp2));
    }
};