class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1, suffix=1, maxi=INT_MIN,i=0;
        while(i<nums.size()){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            prefix *= nums[i];
            suffix *= nums[nums.size()-1-i];
            maxi=max(maxi, max(prefix, suffix));
            i++;
        }
        return maxi;
    }
};