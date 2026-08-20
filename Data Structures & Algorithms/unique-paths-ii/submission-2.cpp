class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int  solve(int i, int j, vector<vector<int>>& obs){
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(obs[i][j] == 1) return 0;

        int right = solve(i,j+1,obs);
        int down = solve(i+1,j,obs);

        return dp[i][j] = right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        m = obs.size();
        n = obs[0].size();
        dp.assign(m+1,vector<int>(n+1,-1));

        if(obs[0][0] == 1 || obs[m-1][n-1] == 1) return 0;

        return solve(0,0,obs);
    }
};