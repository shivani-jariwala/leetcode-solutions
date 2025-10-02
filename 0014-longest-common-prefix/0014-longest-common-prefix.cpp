class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        string compareStr = strs[0];
        for(int i=0; i<compareStr.length(); i++){
            for(int j=1; j<strs.size(); j++) {
                if(strs[j][i]!=compareStr[i]){
                    return compareStr.substr(0, i);
                }
            }
        }
        return compareStr;
    }
};