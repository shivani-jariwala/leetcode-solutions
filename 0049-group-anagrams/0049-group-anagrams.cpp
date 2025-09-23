class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> vec;
        int i=0;
        while(i<strs.size()) {
            string initialStr = strs[i];
            sort(strs[i].begin(), strs[i].end());
            if(mpp.find(strs[i])!=mpp.end()){
                //we got it
                mpp[strs[i]].push_back(initialStr);
            }else{
                //not found
                vector<string> temp = {initialStr};
                mpp[strs[i]] = temp;
            }
            i++;
        }
        for(auto it: mpp) {
            vec.push_back(it.second);
        }
        return vec;
    }
};