class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low =0, high = nums.size()-1;
        int n = nums.size(), mid;
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid] == target) {
                return true;
            }else if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }else if(nums[low] <= nums[mid]){
                //leftSorted
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                //rightSorted
                if(target>=nums[mid] && target<=nums[high]) {
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};