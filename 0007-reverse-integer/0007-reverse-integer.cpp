class Solution {
public:
    int reverse(int x) {
        int n=x;
        long longNum = x;
        long ans=0, mini=INT_MIN, maxi=INT_MAX, rem;
        if(longNum<0) longNum=longNum*(-1);
        while(longNum>0){
            rem = longNum%10;
            ans = (1ll*ans*10) + rem;
            longNum /= 10;
        }   
        if(n<0) ans = (-1)*ans;
        if(ans>maxi || ans<mini)return 0;
        return ans;
    }
};