class Solution {
private:
    int helper(int r, int c, int m, int n, vector<vector<int>>& grid, vector<vector<int>>&dp) {
        if(r>m-1 || c>n-1) return 0;
        if(grid[r][c] == 1) return 0;
        if(r==m-1 && c==n-1) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        int down = helper(r+1, c, m, n, grid, dp);
        int right = helper(r, c+1, m, n, grid, dp);
        dp[r][c] = down+right;
        return down+right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        vector<vector<int>> dp(r, vector<int>(c, -1));
        return helper(0, 0, r, c, obstacleGrid, dp);
    }
};