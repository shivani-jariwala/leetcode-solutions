class Solution {
public:
    string reverseWords(string s) {
        int l=0, r=0;
        vector<string> ans;
        string finalStr = "";
        while(r<s.size()) {
            while(r<s.size() && s[r] == ' ') {
                r++;
            }
            l=r;
            while(r<s.size() && s[r] != ' '){ 
                r++;
            }
            if(r-l>0)ans.push_back(s.substr(l,r-l));
        }
        
        for(int i=ans.size()-1; i>=0; i--) {
            finalStr += ans[i];
            if(i!=0){
                finalStr += " ";
            }
        }
        return finalStr;
    }
};