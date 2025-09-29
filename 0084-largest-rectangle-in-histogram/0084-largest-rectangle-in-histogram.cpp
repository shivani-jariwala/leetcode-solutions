class Solution {
public: 
    vector<int> computeNse(vector<int>& heights) {
        stack<int> st;
        vector<int> nse(heights.size());
        for(int i=heights.size()-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) nse[i]=heights.size();
            else nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> computePse(vector<int>& heights) {
        stack<int> st;
        vector<int> pse(heights.size());
        for(int i=0; i<=heights.size()-1; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        //brute force using Nse and Pse
        int maxi=0;
        int n = heights.size();
        vector<int> nse(n);
        vector<int> pse(n);
        nse=computeNse(heights);
        pse=computePse(heights);
        for(int i=0;i<heights.size();i++){
            maxi = max(maxi, heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};