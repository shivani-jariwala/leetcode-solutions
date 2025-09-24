class Solution {
private: 
    void solve(string digits, vector<string> &combos, vector<string> &ans, int idx, string str) {
        if(idx==digits.length()) {
            ans.push_back(str);
            return;
        }
        int index = digits[idx]-'0';
        cout<<idx<<endl;
        for(int i=0; i<combos[index].size(); i++){
            str.push_back(combos[index][i]);
            solve(digits, combos, ans, idx+1, str);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> combinations = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        solve(digits, combinations, ans, 0, "");
        return ans;
    }
};