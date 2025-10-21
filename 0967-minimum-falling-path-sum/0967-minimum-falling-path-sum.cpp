class Solution {
private:
    long long helper(int r, int c, int m, int n, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        //success case
        if(r>m-1) return 0;
        //failure case
        if(c<0 || c>n-1) return INT_MAX;
        if(r==m) return grid[r][c];
        if(dp[r][c]!=-2) return dp[r][c];
        long long diagLeftIdx = grid[r][c] + helper(r+1,c-1,m,n,grid,dp);
        long long sameIdx = grid[r][c] + helper(r+1,c,m,n,grid,dp);
        long long diagRightIdx = grid[r][c] + helper(r+1,c+1,m,n,grid,dp);
        dp[r][c] = min({diagLeftIdx, sameIdx, diagRightIdx});
        return min({diagLeftIdx, sameIdx, diagRightIdx});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        long long mini = INT_MAX;
        vector<vector<int>> dp(rows,vector<int>(cols, -2));
        for(int i=0; i<matrix[0].size(); i++){
            mini = min(mini,helper(0,i,rows,cols,matrix,dp));
        }
        return mini;
    }
};