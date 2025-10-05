class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp; //num, freq
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        //mip heap //{freq, num}
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        //start pushing to the heap
        for(auto& [num, freq] : mpp){
            pq.push({freq, num});
            if(pq.size() > k){
                pq.pop();
            }
        }
        //it's time to take out the elements from pq
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};