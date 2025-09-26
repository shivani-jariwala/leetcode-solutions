class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;
        //remove whitespace
        int i=0, sign =1;
        long long ans=0;
        int mini = INT_MIN;
        int maxi = INT_MAX;
        while(i<s.length() && s[i]==' ') {
            i++;
        }
        if(s[i]=='-' || s[i]=='+') {
            if(s[i]=='-') sign = -1;
            i++;
        }
        while(i<s.length()){
            if((s[i]-'0'>=0) && (s[i]-'0'<=9)){
                ans = (ans * 10) + s[i]-'0';
                if(sign == -1 && -1*ans<mini) return mini;
                if(sign == 1 && ans>maxi) return maxi;
            }else{
                break;
            }
            i++;
        }
    return ans*sign;
    }
};