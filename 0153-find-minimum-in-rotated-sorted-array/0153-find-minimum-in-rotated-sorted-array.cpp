class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high =nums.size()-1,mid, mini=INT_MAX;
        while(low<=high) {
            mid = (low+high)/2;
            //leftSorted
            if(nums[low]<=nums[mid]) {
                mini = min(mini, nums[low]);
                low = mid+1;                
            }else{
                //rightSorted
                mini = min(mini, nums[mid]);
                high = mid-1;
            }
        }
        return mini;
    }
};