class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, maxf =0, maxlen=0;
        int hash[2]={0};
        while(r<nums.size()) {
            hash[nums[r]]++;
            maxf= max(maxf, hash[1]);
            while(((r-l+1)-maxf)>k) {
                hash[nums[l]]--;
                maxf=0;
                maxf = max(maxf, hash[1]);
                l++;
            }
            if(((r-l+1)-maxf)<=k) maxlen =max(maxlen, (r-l+1));
            r++;
        }
        return maxlen;
    }
};