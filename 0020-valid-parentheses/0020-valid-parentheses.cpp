class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        if(s.length()==1) return false;
        while(i<s.length()) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else{
                if(!st.empty()){
                    char frontEle = st.top();
                    st.pop();
                    if(s[i]==')' && frontEle!='(' || 
                    s[i]=='}' && frontEle!='{' || 
                    s[i]==']' && frontEle!='[') {
                        return false;
                    }
                }else{
                    return false;
                }
            }
            i++;
        }
        return st.empty();
    }
};