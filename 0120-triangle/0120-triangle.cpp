class Solution {
private:
    int helper(int r, int c, int m, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if(r>m-1) return 0;
        if(dp[r][c]!=-2) return dp[r][c];
        int sameIdx = grid[r][c] + helper(r+1,c,m,grid,dp);
        int nextIdx = grid[r][c] + helper(r+1,c+1,m,grid,dp);
        dp[r][c] = min(sameIdx, nextIdx);
        return min(sameIdx, nextIdx);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int dpCols = triangle[rows-1].size();
        vector<vector<int>> dp(rows, vector<int>(dpCols,-2));
        return helper(0,0,rows,triangle, dp);
    }
};