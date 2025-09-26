class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st; //75, 1
        vector<int> ans(temperatures.size(),0);
        for(int i=temperatures.size()-1; i>=0; i--){
            while(!st.empty() && st.top().first<=temperatures[i]) {
                st.pop();
            }
            if(st.empty()) ans[i]=0;
            else ans[i] = st.top().second-i;
            st.push({temperatures[i], i});
        }
        return ans;
    }
};