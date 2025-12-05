class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(char digit: num) {
            while(ans.length()>0 && ans.back() > digit && k>0) {
                ans.pop_back();
                k--;
            }
            ans.push_back(digit);
        }
        while(k>0 && ans.length()>0){
            ans.pop_back();
            k--;
        }
        int i =0;
        while(i<ans.length() && ans[i]=='0') i++;
        while(i==ans.length()) return "0";
        return ans.substr(i);
    }
};