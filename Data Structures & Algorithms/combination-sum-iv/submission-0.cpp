class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int solve(int i, int target, vector<int>& nums){
        if(i == n) return target == 0;
        if(target == 0) return 1;
        if(dp[i][target] != -1) return dp[i][target];
        int take = 0;
        if(nums[i] <= target){
            take = solve(0, target-nums[i],nums);
        }
        int notTake = solve(i+1, target,nums);

        return dp[i][target] = take + notTake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        dp.assign(n+1,vector<int>(target+1,-1));
        return solve(0,target,nums);
    }
};