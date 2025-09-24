class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0; i<s.length(); i++){
            for(int j=s.length()-1; j>=i;j--){
                if(s[i] == s[j]) {
                    int x=i;
                    int y=j;
                    while(x<=y && s[x]==s[y]){
                        x++;
                        y--;
                    }
                    if(x>y) {
                        string newStr = s.substr(i, j-i+1);
                        if(newStr.length()>ans.length()) ans = newStr;
                    }
                }
            }
        }
        return ans;
    }
};