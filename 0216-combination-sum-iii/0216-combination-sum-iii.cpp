class Solution {
private:
    void buildCombination(int num, int k, int n, vector<vector<int>> &finalAns, vector<int> &singleAns) {
        if(n==0) {
            if(singleAns.size() == k){
                finalAns.push_back(singleAns);
            }
            return;
        }
        if(num>9) {
            return;
        }
        singleAns.push_back(num);
        buildCombination(num+1, k, n-num, finalAns, singleAns);
        singleAns.pop_back();
        buildCombination(num+1, k, n, finalAns, singleAns);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> finalAns;
        vector<int> singleAns;
        buildCombination(1, k, n, finalAns, singleAns);
        return finalAns;
    }
};