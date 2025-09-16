class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, maxf =0, maxLen = 0;
        unordered_map<char, int> hash;
        while(r<s.size()) {
            hash[s[r]-'A']++;
            maxf = max(maxf, hash[s[r]-'A']);
            int changes = (r-l+1) - maxf;
            if(changes>k){
                maxf=0;
                while(changes>k){
                    hash[s[l]-'A']--;
                    for(int i=0; i<=25; i++) {
                        maxf = max(maxf, hash[i]);
                    }
                    l++;
                    changes = (r-l+1) - maxf;
                }
            }
            maxLen = max(maxLen, (r-l+1));
            r++;
        }
        return maxLen;
    }
};