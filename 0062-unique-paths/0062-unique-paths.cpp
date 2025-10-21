class Solution {
private:
    int helper(int r, int c, int m, int n, vector<vector<int>>&dp) {
        if(r==m-1 && c==n-1) return 1;
        if(r>m-1 || c>n-1) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        int down = helper(r+1, c, m, n, dp);
        int right = helper(r, c+1, m, n, dp);
        dp[r][c] = down+right;
        return down+right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0,0,m,n,dp);
    }
};