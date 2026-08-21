class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int solve(int i, int target, vector<int>& nums){
        
        if(i == n) return target == 0;

        if(dp[i][target+1000] != -1) return dp[i][target+1000];

        int plus = solve(i+1,target-nums[i],nums);
        int minus = solve(i+1,target+nums[i],nums);

        return dp[i][target+1000] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        dp.assign(n+1,vector<int>(2001,-1));
        return solve(0,target,nums);
    }
};
