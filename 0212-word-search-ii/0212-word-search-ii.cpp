class Solution {
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        TrieNode(){
            for(int i = 0; i<26;i++){
                children[i]=nullptr;
            }
            isEnd = false;
        }
    };
    TrieNode* root;
    vector<string>res;
    void insert(string s){
        TrieNode* node = root;
        for(char ch: s){
            if(!node->children[ch-'a']){
                node->children[ch-'a'] = new TrieNode();
            }
            node = node->children[ch-'a'];
        }
        node->isEnd = true;
    }
    void dfs(int r, int c, vector<vector<char>>& board, string &word, TrieNode* node){
        char ch =board[r][c];
        if(ch=='#' || !node->children[ch-'a']) return;
        TrieNode* nextNode = node->children[ch-'a'];
        word.push_back(ch);
        if(nextNode->isEnd){
            res.push_back(word);
            nextNode->isEnd = false;
        }
        board[r][c]='#';
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};
        for(int i =0; i< 4;i++){
            int newRow = r + dRow[i];
            int newCol = c + dCol[i];
            if(newRow>=0 && newRow<board.size() && newCol >=0 && newCol<board[0].size()){
                dfs(newRow, newCol, board, word, nextNode);
            }
        }
        board[r][c]= ch;
        word.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        //build tree
        for(string s:words){
            insert(s);
        }
        //start iterating over the board
        int m = board.size();
        int n = board[0].size();
        string word="";
        for(int i=0;i<m; i++){
            for(int j=0;j<n;j++){
                if(root->children[board[i][j]-'a']!=nullptr){
                    dfs(i,j,board,word,root);
                }
            }
        }
        return res;
    }
};