class Solution {
public:
    int count = 0;
    bool isSafe(vector<string> &board , int row , int col , int n){
        // horizontal - 
        for(int j = 0 ; j < n ; j++){
            if(board[row][j] == 'Q') return false;
        }

        // vertical -
        for(int i = 0 ; i < n ; i++){
            if(board[i][col] == 'Q') return false;
        }

        // Diagonal-
        // Left 
        for(int i = row,j = col ; i >= 0 && j >= 0 ; i--,j--){
            if(board[i][j] == 'Q') return false;
        }

        // Right
        for(int i = row , j = col ; i >= 0 && j < n ; i--,j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }
    void nQueen(vector<string> &board, int row, int n){
        if(row == n){
            count++;
            return;
        }

        for(int j = 0; j < n; j++){
            if(isSafe(board , row , j , n)){
                board[row][j] = 'Q';
                nQueen(board , row+1 , n );
                board[row][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        nQueen(board,0,n);
        return count;
    }
};