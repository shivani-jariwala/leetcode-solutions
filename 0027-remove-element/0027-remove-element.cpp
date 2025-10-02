class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0, j= nums.size()-1;
        while(i<nums.size() && i<=j){
            if(nums[i]!=val){
                i++;
            }else{
                //if equal then swap
                swap(nums[i], nums[j]);
                j--;
            }
        }
        return i;
    }
};