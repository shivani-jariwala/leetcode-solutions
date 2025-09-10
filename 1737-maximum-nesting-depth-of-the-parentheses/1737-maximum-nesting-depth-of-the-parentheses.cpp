class Solution {
public:
    int maxDepth(string s) {
       if(s==""|| s==" ") return 0;
       int cnt =0, maxi=0;
       for(int i=0; i<s.length();i++) {
            if(s[i]=='(') cnt ++;
            if(s[i]==')') cnt --;
            maxi = max(maxi, cnt);
       }
       return maxi;
    }
};