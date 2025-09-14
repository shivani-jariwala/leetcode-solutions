class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
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