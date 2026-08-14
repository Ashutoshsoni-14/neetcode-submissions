class Solution {
public:
    vector<int> dp;
    int solve(int i, vector<int>& cost){
        if(i >= cost.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];

        int a = cost[i] + solve(i+1,cost);
        int b = cost[i] + solve(i+2,cost);

        return dp[i] = min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 2) return min(cost[0] , cost[1]);

        dp.assign(n+1,-1);
        int a = solve(0,cost);
        dp.clear();
        int b = solve(1,cost);

        return min(a,b); 
    }
};
