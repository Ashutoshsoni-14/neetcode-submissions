// Recursion  -
class Solution {
public:
    vector<vector<int>> dp;
    int n, sum;
    bool solve(int i, int target, vector<int>& nums){
        if(i == n) return target == sum/2;

        if(target == sum/2) return dp[i][target] = true;

        if(dp[i][target] != -1) return dp[i][target];

        bool take = false;
        if(nums[i] <= target){
            take = solve(i+1,target-nums[i],nums);
        }
        bool notTake = solve(i+1,target,nums);

        return dp[i][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        sum = accumulate(nums.begin(),nums.end(),0);

        // if sum is odd then it can't be split in two equal half
        if(sum % 2 == 1) return false;

        dp.assign(n+1,vector<int>(sum+1,-1));

        return solve(0,sum,nums);
    }
};
