class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.00;
        long long nn=n;
        if(n<0) nn = -1*nn;
        while(nn){ //until nn is not zero, breaks as soon as nn = 0
            if(nn%2==0) {
                //even
                x=x*x;
                nn = nn/2;
            }else{
                //odd
                ans = ans * x;
                nn = nn-1;
            }
        }
        if(n<0) return 1/ans;
        return ans;
    }
};