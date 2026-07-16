class Solution {
public:
    bool check(vector<vector<char>>& board , int row , int col , char dig){
        for(int i = 0 ;i<9 ;i++){
            if(i!=row && board[i][col] == dig) return false;
        }
        for(int j = 0 ;j<9 ;j++){
            if(j!=col && board[row][j] == dig) return false;
        }
        int sr = (row/3)*3;
        int sc = (col/3)*3;
        for(int i = sr ;i<=sr+2 ;i++){
            for(int j = sc ;j<=sc+2 ;j++){
                if(i!=row && j!=col && board[i][j] == dig) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] != '.' && !check(board,i,j,board[i][j])) return false;
            }
        }
        return true;
    }
};
