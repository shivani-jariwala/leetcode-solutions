class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int n = s.length();
        int r = n-1;
        int sum = 0;
        while(r>=0){
            if(r==n-1){
                sum = sum + mpp[s[r]];
            } else if(mpp[s[r]]>=mpp[s[r+1]]){
                sum = sum + mpp[s[r]];
            }else{
                sum = sum - mpp[s[r]];
            }
            r--;
        }
        return sum;
    }
};