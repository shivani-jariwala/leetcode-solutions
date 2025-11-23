class Solution {
private:
    void bfs(int i, int j,vector<vector<char>>& grid, vector<vector<int>>& vis, int m, int n){
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        //up, right, down, left
        int dRow[]={-1, 0, 1, 0};
        int dCol[]={0,1,0,-1};

        while(!q.empty()){
            //take out the node here is the starting node
            int myRow = q.front().first;
            int myCol = q.front().second;
            q.pop();
            //computer all neighbours of this myRow and myCol 
            // for(int row = -1; row<=1; row++){
            //     for (int col=-1; col<=1; col++) { //moves in all 3 directions
            //         int nRow = myRow+row;
            //         int nCol = myCol+col;
            //         if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && grid[nRow][nCol]=='1' && !vis[nRow][nCol]){
            //             vis[nRow][nCol] =1;
            //             q.push({nRow,nCol});
            //         }
            //     }
            // }

                for (int k=0; k<4; k++) { //moves in all 4 directions
                    int nRow = myRow+dRow[k];
                    int nCol = myCol+dCol[k];
                    if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && grid[nRow][nCol]=='1' && !vis[nRow][nCol]){
                        vis[nRow][nCol] =1;
                        q.push({nRow,nCol});
                    }
                }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int cnt =0;
        //find start point
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i, j, grid, vis, m, n);
                }
            }
        }
        return cnt;
    }
};