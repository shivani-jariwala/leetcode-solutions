class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, cnt=0;
        unordered_map<int,int> mpp;
        while(r<s.size()){
            mpp[s[r]]++;
            while(mpp[s[r]]>1){
                mpp[s[l]]--;
                l++;
            }
            cnt=max(cnt, r-l+1);
            r++;
        }
        return cnt;
    }
};