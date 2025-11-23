class Solution {
private:
    int helper(int r1, int c1, int c2, int rows, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        //base case
        //out-of-bounds
        int r2= r1+c1-c2;
        if(r1>=rows || r2>=rows || c1>=rows || c2>=rows) return -1e9;
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1) return -1e9;
        if(r1==rows-1 && c1==rows-1) return grid[r1][c1];
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        //main logic
        //if at same place
        int cherries=0;
        if(r1==r2 && c1==c2) {
            cherries=grid[r1][c1];
        } else {
            cherries=grid[r1][c1] + grid[r2][c2];
        } 
        int f1= helper(r1, c1+1, c2+1, rows, grid, dp);//RR
        int f2=helper(r1, c1+1, c2, rows, grid, dp);//RD
        int f3=helper(r1+1, c1, c2+1, rows, grid, dp);//DR
        int f4=helper(r1+1, c1, c2, rows, grid, dp);//DD
        cherries+=max({f1,f2,f3,f4});
        return dp[r1][c1][c2]= cherries;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(); //n*n grid
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n,-1)));
        int result = helper(0,0,0, n ,grid, dp);
        return max(0, result);
    }
};