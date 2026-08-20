class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>> & grid){
        // destination - 
        if(i == m-1 && j == n-1) return grid[i][j];

        // already exists
        if(dp[i][j] != -1) return dp[i][j];

        // i = last row -> can only move right
        if(i == m-1){
            return dp[i][j] = grid[i][j] + solve(i,j+1,grid);
        }

        // j = last col -> can only move down
        else if(j == n-1){
            return dp[i][j] = grid[i][j] + solve(i+1,j,grid);
        }

        // normal case -
        else{
            return dp[i][j] = grid[i][j] + min(solve(i,j+1,grid) , solve(i+1,j,grid));
        }

    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m,vector<int>(n,-1));

        return solve(0,0,grid);
    }
};