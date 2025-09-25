class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProd(nums.size());
        vector<int> ans(nums.size());
        int suffix=1;
        prefixProd[0] = nums[0];
        for(int i=1;i<n;i++) {
            prefixProd[i]=nums[i]*prefixProd[i-1];
        }
        for(int i=n-1; i>0;i--) {
            ans[i] = prefixProd[i-1]*suffix;
            suffix = suffix*nums[i];
        }
        ans[0] = suffix;
        return ans;

    }
};