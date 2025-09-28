class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0, cnt=0, i=0;        
        unordered_map<int,int> mpp; //sum,count
        mpp[0]=1;
        while(i<nums.size()){
            sum += nums[i];
            int diff = sum - k;
            if(mpp[diff]) cnt += mpp[diff];
            mpp[sum] = mpp[sum]+1;
            i++;
        }
        return cnt;
    }
};