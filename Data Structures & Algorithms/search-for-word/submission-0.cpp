class Solution {
public:
    int m,n;
    bool solve(int i, int j, string &word, vector<vector<char>>& board, int idx){
        if(idx == word.length()) return true;

        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '*') return false;

        if(board[i][j] != word[idx]) return false;

        char ch = board[i][j];
        board[i][j] = '*'; // visit kara diya 

        bool search = solve(i+1,j,word,board,idx+1) || 
                      solve(i,j+1,word,board,idx+1) ||
                      solve(i-1,j,word,board,idx+1) ||
                      solve(i,j-1,word,board,idx+1) ;

        board[i][j] = ch; // backtrack kar liya 

        return search;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && solve(i,j,word,board,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
