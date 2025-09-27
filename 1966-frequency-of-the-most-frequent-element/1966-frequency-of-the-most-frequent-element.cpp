class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=0,maxi=0;
        long long sum=0;
        while(r<nums.size()) {
            sum += nums[r];
            while(1ll*nums[r]*(r-l+1) > sum+k) {
                //excedding our available cost
                sum -= nums[l];
                l++;
            }
            maxi = max(maxi, (r-l+1));
            r++;
        }
        return maxi;
    }
};