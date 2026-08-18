class Solution {
public:
    vector<vector<int>> dp;
    int n ;
    
    int solve(int i, int p, vector<int> & nums){
        if(i >= n) return 0;

        if(p != -1 && dp[i][p] != -1) return dp[i][p];

        int take = INT_MIN;
        if(p == -1 || nums[i] > nums[p]){
            take = 1 + solve(i+1 , i , nums);
        }
        int notTake = solve(i+1 , p , nums);

        if(p != -1){
            dp[i][p] = max(take , notTake);
        }

        return max(take , notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums);
    }
};
