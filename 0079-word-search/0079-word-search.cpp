class Solution {
private:
    bool searchInMat(vector<vector<char>>& board, int n, int m, string word, int i, int j, int idx){
        //base
        if(idx == word.length()) return true;
        if(i>n-1 || i<0 || j>m-1 || j<0 ) return false;
        if(board[i][j]!=word[idx]) return false;
        char temp = board[i][j];
        board[i][j]='#';
        bool op = searchInMat(board, n, m, word, i-1, j, idx+1) || searchInMat(board, n, m, word, i, j+1, idx+1) || searchInMat(board, n, m, word, i+1, j, idx+1) || searchInMat(board, n, m, word, i, j-1, idx+1);
        board[i][j] = temp;
        return op;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
        int m=board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(searchInMat(board, n, m, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};