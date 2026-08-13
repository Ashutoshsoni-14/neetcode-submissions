class Solution {
public:
    vector<int> dp;
    int solve(int i , int end , vector<int>& nums){
        if(i > end) return 0;

        if(dp[i] != -1){
            return dp[i];
        }
        int steal = nums[i] + solve(i+2,end,nums);
        int skip = solve(i+1,end,nums);

        return dp[i] = max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        dp.assign(n+1,-1);
        int res1 = solve(0,n-2,nums);

        dp.assign(n+1,-1);
        int res2 = solve(1,n-1,nums);

        return max(res1,res2);

    }
};
