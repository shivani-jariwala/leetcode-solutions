class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> st;
        int maxLen=1;
        //using set bcoz the array can have duplicates
        for(int i=0;i<nums.size();i++) {
            st.insert(nums[i]);
        }
        for(auto it: st) {
            int cnt = 1;
            if(st.find(it-1) == st.end()) {
                //we did not found it so leave it is the starting point
                auto x = it;
                while(st.find(x+1) != st.end()){
                    //we found it
                    x = x+1;
                    cnt += 1;
                }
                maxLen = max(maxLen, cnt);
            }
        }
    return maxLen;
    }
};