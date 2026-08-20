class Solution {
public:
    int n, sum;
    vector<int> dp;
    bool solve(vector<int> & nums, int i, int target){
        if(i == n) return target == sum/2 ;

        if(dp[target] != -1) return dp[target];
        bool take = false;
        if(nums[i] <= target){
            take = solve(nums,i+1,target-nums[i]);
        }
        bool notTake = solve(nums,i+1,target);

        return dp[target] = take || notTake ;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        sum = accumulate(nums.begin(),nums.end(),0);

        if(sum % 2 == 1) return false;

        dp.assign(sum+1,-1);
        return solve(nums,0,sum);
    }
};
