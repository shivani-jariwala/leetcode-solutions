class Solution {
private:
    void bfs(int sr, int sc, int color,vector<vector<int>>& grid){
    queue<pair<int,int>> q;
    q.push({sr,sc});
    int ogColor = grid[sr][sc];
    grid[sr][sc]=color; 
    int dRow[]={-1,0,1,0};
    int dCol[]={0,1,0,-1};
    int rows = grid.size();
    int cols = grid[0].size();

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int k=0 ;k<4; k++) {
            int nRow = r + dRow[k];
            int nCol = c + dCol[k];
            if(nRow>=0 && nCol>=0 && nRow<rows && nCol<cols && grid[nRow][nCol]==ogColor) {
                grid[nRow][nCol] = color;
                q.push({nRow, nCol});
            }
        }
    }  
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        if(image[sr][sc]==color) return image;
        bfs(sr,sc,color,image);
        return image;
    }
};