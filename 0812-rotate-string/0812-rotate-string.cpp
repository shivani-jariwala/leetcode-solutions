class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        int n = s.length();
        string l ="";
        for(int i=0; i<n; i++) {
            string r = s.substr(i);
            if(r+l == goal) return true;
            l += s[i];
        }
        return false;
    }
};