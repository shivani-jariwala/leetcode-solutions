class Solution {
private:
    void computerParantheses(int n, int &open, int &close, vector<string> &finalAns, string &ans) { 
        if(open==n && close==n) {
            finalAns.push_back(ans);
            return;
        }
        if(open<=n) {
            ans += '(';
            open = open +1;
            computerParantheses(n, open, close, finalAns, ans);
            open = open-1;
            ans.pop_back();
        }
        if(close<open){
            ans += ')';
            close = close +1;
            computerParantheses(n, open, close, finalAns, ans);
            close = close-1;
            ans.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string ans="";
        vector<string> finalAns;
        int open=0, close=0;
        computerParantheses(n, open, close, finalAns, ans);
        return finalAns;
    }
};