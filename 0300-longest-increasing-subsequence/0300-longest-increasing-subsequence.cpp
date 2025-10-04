class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int n=nums.size();
        //1-d dp of size n and initially 1 since every value can be a subsequence individually
        vector<int> dp(n,1); 
        for(int i=1; i<n;i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int maxi = dp[0];
        for(int i=1;i<dp.size();i++){
            if(dp[i]>dp[i-1]) maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};