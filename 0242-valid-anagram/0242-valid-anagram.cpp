class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int hash[26] = {0};
        int i = 0;
        while(i<s.length()){
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;
            i++;
        }
        for(int i=0; i<26; i++) {
            if(hash[i]!=0) return false;
        }
        return true;
    }
};