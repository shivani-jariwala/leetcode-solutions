class Solution {
private: 
    void helper(vector<int> arr, int index, int target, vector<int> &singleAns, set<vector<int>> &finalAns) {
        if(target<=0 || index==arr.size()) {
            if(target == 0) finalAns.insert(singleAns);
            return;
        }
        singleAns.push_back(arr[index]);
        helper(arr, index, target-arr[index], singleAns, finalAns);
        helper(arr, index+1, target-arr[index], singleAns, finalAns);
        singleAns.pop_back();
        helper(arr, index+1, target, singleAns, finalAns);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> singleAns;
        set<vector<int>> finalAns;
        vector<vector<int>> ans;
        helper(candidates, 0, target, singleAns, finalAns);
        for(auto vec: finalAns) {
            ans.push_back(vec);
        }
        return ans;
    }
};