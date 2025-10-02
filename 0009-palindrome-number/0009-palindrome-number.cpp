class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long ogNum = x;
        long sum=0;
        while(x!=0){
            sum = sum*10 + (x%10);
            x=x/10;
        }
        return ogNum == sum;
    }
};