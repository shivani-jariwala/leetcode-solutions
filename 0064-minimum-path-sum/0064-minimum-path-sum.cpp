class Solution {
private:
    long long helper(int r, int c, int m, int n, vector<vector<int>>& grid, vector<vector<int>>&dp) {
        if(r>m-1 || c>n-1) return INT_MAX;
        if(r==m-1 && c==n-1) return grid[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        long long down = grid[r][c] + helper(r+1, c, m, n, grid, dp);
        long long right = grid[r][c] + helper(r, c+1, m, n, grid, dp);
        dp[r][c] = min(down,right);
        return min(down,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return helper(0,0,rows,cols,grid,dp);
    }
};