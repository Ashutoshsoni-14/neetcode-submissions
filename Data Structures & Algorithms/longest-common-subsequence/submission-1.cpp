// recursion + memo
class Solution {
public:
    vector<vector<int>> dp;
    int m,n;
    int solve(int i, int j, string &s1, string &s2){
        if(i == m || j == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(i+1,j+1,s1,s2);
        }
        return dp[i][j] = max(solve(i+1,j,s1,s2) , solve(i,j+1,s1,s2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size();
        n = text2.size();
        dp.assign(m+1,vector<int>(n+1,-1));
        return solve(0,0,text1,text2);
    }
};
