class Solution {
private:
    void helper(vector<int> arr, int index, vector<int>& container, vector<vector<int>> &finalAns){
        if(index>=arr.size()) {
            finalAns.push_back(container);
            return;
        }
        container.push_back(arr[index]);
        helper(arr, index+1, container, finalAns);
        container.pop_back();
        helper(arr, index+1, container, finalAns);
    } 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> container;
        vector<vector<int>> finalAns;
        helper(nums, 0, container, finalAns);
        return finalAns;
    }
};