class Solution {
public:
    vector<int> dp;
    int solve(int n){
        if(n == 0) return 0;

        if(dp[n] != -1) return dp[n];
        
        int minCount = INT_MAX;
        for(int i = 1; i*i <=n; i++){
            int count = 1 + solve(n-i*i);

            minCount = min(minCount , count);
        }
        return dp[n] = minCount;
    }
    int numSquares(int n) {
        dp.assign(n+1,-1);
        return solve(n);
    }
};