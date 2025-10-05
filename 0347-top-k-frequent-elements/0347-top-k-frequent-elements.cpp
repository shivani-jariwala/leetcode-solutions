class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //using bucket sort
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0;i<n; i++){
            mpp[nums[i]]++;
        }
        //[[],[3],[2],[1],[],[],[]]
        vector<vector<int>> buckets(n+1);
        for(auto &[num, freq]: mpp) {
            buckets[freq].push_back(num);
        }
        vector<int> ans;
        //start iterating from back over buckets for k times
        for(int i=n; i>=1; i--){
            if(!buckets[i].empty()){
                for(auto& it: buckets[i]) {
                    if(ans.size() ==k) break;
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};