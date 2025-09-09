class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0, r=0, cnt=0;
        int hash[3]={0};
        while(r<s.size()) {
            hash[s[r]-'a']++;
            while(hash[0]>=1 && hash[1]>=1 && hash[2]>=1) {
                cnt += (s.size()-r);
                hash[s[l]-'a']--;
                l++;
            }
            if(hash[0]>=1 && hash[1]>=1 && hash[2]>=1){
                cnt += (s.size()-r);
            }
            r++;
        }
        return cnt;
    }
};