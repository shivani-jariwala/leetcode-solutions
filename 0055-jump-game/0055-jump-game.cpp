class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx=0;
        for(int i=0;i<nums.size();i++){
            //never touched this index
            if(maxIdx<i) return false;
            maxIdx = max(maxIdx, (i+nums[i]));
            if(maxIdx>=nums.size()) return true;
        }
        return true;
    }
};