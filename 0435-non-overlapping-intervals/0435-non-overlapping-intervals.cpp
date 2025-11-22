class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //this is greddy algo
        sort(intervals.begin(), intervals.end(), [](const vector<int> a, const vector<int> b){
            return a[1]<b[1];
        });
        int deducts=0, i=1;
        int n = intervals.size();
        vector<int> prev = intervals[0];
        while(i<n) {
            if(intervals[i][0]<prev[1]){
                deducts++;
            }else{
                prev = intervals[i];
            }
            i++;
        }
        return deducts;
    }
};