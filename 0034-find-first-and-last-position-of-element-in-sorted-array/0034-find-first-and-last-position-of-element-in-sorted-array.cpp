class Solution {
private:
    int findFirst(vector<int>& nums, int target){
        int n=nums.size();
        int low =0, high=n-1, mid, first=-1;
        while(low<=high) {
            mid = (low+high)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }else if(nums[mid]<target){
                low =mid+1;
            }else{
                high=mid-1;
            }
        }
        return first;
    }
    int findLast(vector<int>& nums, int target){
        int n=nums.size();
        int low =0, high=n-1, mid, last=-1;
        while(low<=high) {
            mid = (low+high)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }else if(nums[mid]<target){
                low =mid+1;
            }else{
                high=mid-1;
            }
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        if(first==-1) return {-1,-1};
        int last = findLast(nums, target);
        return {first,last};
    }
};