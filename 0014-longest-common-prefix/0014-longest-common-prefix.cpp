class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size()==1) return strs[0];
        string first = strs[0];
        for (int i=0; i<first.size(); i++) {
            for (int j =1; j<strs.size(); j++) {
                if(strs[j][i] != first[i] ) {
                    return first.substr(0, i);
                }
            }
        }
        return first;
    }
};