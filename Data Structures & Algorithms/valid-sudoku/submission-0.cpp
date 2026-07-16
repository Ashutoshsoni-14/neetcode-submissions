class Solution {
public:
    bool check(vector<vector<char>> &board , int row ,int col , char digit){
        // column is fixed : traverse on row
        for(int i = 0;i<9;i++){
            if(i!=row && board[i][col] == digit) return false;
        }
        // column is fixed : traverse on row
        for(int j = 0;j<9;j++){
            if(j!=col && board[row][j] == digit) return false;
        }
        // check on sub-square:
        int sr = (row/3)*3; // starting row
        int sc = (col/3)*3; // starting col
        for(int i = sr;i<sr+3;i++){
            for(int j = sc;j<sc+3;j++){
                if(i!=row && j!=col && board[i][j] == digit) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] != '.' && check(board , i , j , board[i][j]) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
