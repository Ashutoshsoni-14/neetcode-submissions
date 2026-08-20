// Bottom up-
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size();
        int n = obs[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int j = 0; j < n; j++){
            if(obs[0][j] != 1) dp[0][j] = 1;
            else break;
        }
        for(int i = 0; i < m; i++){
            if(obs[i][0] != 1) dp[i][0] = 1;
            else break;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obs[i][j] != 1) dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};