class Solution {
public:
    // Bottom up approach-
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        dp.assign(n+1,0);

        dp[0] = 0; // no house take
        dp[1] = nums[0]; // first house take 

        // ith index of dp -> (i-1)th house take or not -> max profit
        for(int i = 2; i<=nums.size(); i++){
            int steal = nums[i-1] + dp[i-2];
            int skip  = dp[i-1];
            dp[i] = max(steal,skip);
        }
        return dp[n];

    }
};
