class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore's voting algo
        int cnt =0, ele;
        for(int i=0; i<nums.size(); i++) {
            if (cnt==0) {
                ele = nums[i];
                cnt =1;
            }else if(ele == nums[i]) {
                cnt++;
            }else{
                cnt--;
            }
        }
        if(cnt>nums.size()/2){
            return ele;
        }
        return ele;
    }
};