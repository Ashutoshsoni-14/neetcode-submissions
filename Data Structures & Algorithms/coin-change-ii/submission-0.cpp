class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int solve(int i, vector<int>& coins, int target){
        if(i == n) return target == 0;
        if(dp[i][target] != -1) return dp[i][target];
        int take = 0;
        if(coins[i] <= target){
            take = solve(i,coins,target-coins[i]);
        }
        int skip = solve(i+1,coins,target);

        return dp[i][target] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.assign(n+1,vector<int>(amount+1,-1));
        return solve(0,coins,amount);
    }
};
