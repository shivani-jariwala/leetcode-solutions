class Solution {
private:
    long helper(int idx, vector<int>& arr, int buy, vector<vector<int>>& dp) {
        //base case
        if(idx==arr.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        long profit = 0;
        if(buy) {
            //can buy
            profit = max(-arr[idx] + helper(idx+1, arr, 0, dp), helper(idx+1, arr, 1, dp));
        }else {
            //can sell
            profit = max(arr[idx] + helper(idx+1, arr, 1, dp), helper(idx+1, arr, 0, dp));
        }
        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, prices, 1, dp);
    }
};