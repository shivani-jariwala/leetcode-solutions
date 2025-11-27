class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int mid = nums[n/2];

        auto start = lower_bound(nums.begin(), nums.end(), mid);
        auto end = upper_bound(nums.begin(), nums.end(), mid);

        int maxFreq = end - start;

        if(maxFreq> n/2){
            return maxFreq - (n-maxFreq);
        }
        return n%2;
    }
};