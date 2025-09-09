class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        if(s.length()==1 && t.length()==1) return true;
        unordered_map<char, char> mpp;
        string res = "";
        for(int i=0; i<s.size(); i++) {
            if(mpp.count(s[i])) res += mpp[s[i]];
            else {
                for(auto &pair: mpp) {
                    if( pair.second == t[i]) return false;
                }
                mpp[s[i]] = t[i];
                res += t[i];
            }
        }
        return res==t;
    }
};