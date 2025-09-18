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
            int currEle = arr[index];
            while(index<arr.size() && currEle == arr[index]) {
                index++;
            }
            helper(arr, index, container, finalAns);
    } 
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> container;
        vector<vector<int>> finalAns;
        sort(nums.begin(), nums.end());
        helper(nums, 0, container, finalAns);
        return finalAns;
    }
};