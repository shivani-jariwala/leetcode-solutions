class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low=0, high=n-1, mid;
        while(low<=high) {
            mid = (low+high)/2;
            if((nums[mid]!=nums[mid-1]) && (nums[mid]!=nums[mid+1])) {
                return nums[mid];
            }else if((mid%2==0 && nums[mid-1]==nums[mid]) || (mid%2==1 && nums[mid]==nums[mid+1])){
                //right side is fine, element is on left
                high = mid-1;
            }else{
                //left side is fine, element is on right
                low = mid+1;
            }
        }
        return -1;
    }
};