class Solution {
public:
    string largestOddNumber(string num) {
        int r= num.size() -1;
        while(r>=0) {
            if((num[r]-'0')%2 !=0) {
                string word = num.substr(0, r+1);
                return word;
                break;
            }
            r--;
        }
        return "";
    }
};