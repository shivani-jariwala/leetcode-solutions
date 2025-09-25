class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //whenever rotation think of imaginary array on right side
        int index;
        vector<int> ans(nums.size(),-1);
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<i+n; j++) {
                index = j% n;
                if(nums[index]>nums[i]){
                     ans[i] = nums[index];
                    break;
                }
            }
        }
        return ans;
    }
};