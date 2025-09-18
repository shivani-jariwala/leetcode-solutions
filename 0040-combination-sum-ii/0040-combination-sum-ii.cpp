class Solution {
private: 
    void helper(vector<int> arr, int index, int target, vector<int> &singleAns, vector<vector<int>> &finalAns) {
        if(target<=0 || index==arr.size()) {
            if(target==0) finalAns.push_back(singleAns);
            return;
        }
        singleAns.push_back(arr[index]);
        helper(arr, index+1, target-arr[index], singleAns, finalAns);
        singleAns.pop_back();
        int currEle = arr[index];
        while(index<arr.size() && currEle == arr[index]) {
            index++;
        }
        helper(arr, index, target, singleAns, finalAns);
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> singleAns;
        vector<vector<int>> finalAns;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, singleAns, finalAns);
        return finalAns;
    }
};