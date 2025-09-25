class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        for(int i=1;i<intervals.size();i++){
            vector<int> temp = intervals[i];
            if((temp[0]<=prev[1] && temp[0]>=prev[0])){
                prev[1]=max(prev[1], temp[1]);
            }else{
                ans.push_back(prev);
                prev=temp;
            }
        }
        ans.push_back(prev);
        return ans;
    }
};