class Solution {
private: 
    void helper(vector<int>& nums, vector<vector<int>> &finalAns, vector<int> &ans, int target, int idx){
        if(target<=0 || idx==nums.size()) {
            if(target==0) finalAns.push_back(ans);
            return;
        }
        ans.push_back(nums[idx]);
        helper(nums, finalAns, ans, target-nums[idx], idx);
        ans.pop_back();
        helper(nums, finalAns, ans, target, idx+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> finalAns;
        vector<int> ans;
        helper(candidates, finalAns, ans, target, 0);
        return finalAns;
    }
};