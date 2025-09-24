class Solution {
public:
    int numberOfSubstrings(string s) {
        //optimal approach
        //find the minimum index where we found abc and then count all the sub-strings uptil the index 0 i.e. starting
        int n = s.length();
        int l=0, r=0, cnt=0;
        int hash[3] = {-1,-1,-1};
        while(r<n) {
            hash[s[r]-'a'] = r;
            if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1) {
                cnt = cnt + (1+min(min(hash[0], hash[1]), hash[2]));
            }
            r++;
        }
        return cnt;
    }
};