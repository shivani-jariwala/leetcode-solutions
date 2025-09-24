class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt =0, maxi = 0;
        int i=0;
        while(i<nums.size()) {
            if(nums[i]==0) cnt=0;
            else cnt++;
            maxi = max(maxi, cnt);
            i++;
        }
        return maxi;
    }
};