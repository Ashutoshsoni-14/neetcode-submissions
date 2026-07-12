class Solution {
public:
    void dfs(int i ,int j ,int n ,int m ,vector<vector<bool>> & vis , vector<vector<char>>& board){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || board[i][j] == 'X'){
            return ;
        }
        vis[i][j] = true;
        dfs(i-1,j,n,m,vis,board);
        dfs(i+1,j,n,m,vis,board);
        dfs(i,j-1,n,m,vis,board);
        dfs(i,j+1,n,m,vis,board);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        //check left and right boundary- 
        for(int i = 0; i<n ;i++){
            if(board[i][0] == 'O') dfs(i,0,n,m,vis,board);
            if(board[i][m-1] == 'O') dfs(i,m-1,n,m,vis,board);
        }
        //check top and bottom boundary- 
        for(int j = 0; j<m ;j++){
            if(board[0][j] == 'O') dfs(0,j,n,m,vis,board);
            if(board[n-1][j] == 'O') dfs(n-1,j,n,m,vis,board);
        }
        // all unvisited 'O' cells convert it to -> 'X' 
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == 'O' && vis[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
