class Solution {
public:
    vector<vector<int>> dp;
    int m, n;
    int solve(int i, int j, string& s1, string& s2){
        if(i == m) return n-j; // insertions
        if(j == n) return m-i; // deletions
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return solve(i+1,j+1,s1,s2);
        else{
            int insert = 1 + solve(i,j+1,s1,s2);
            int del = 1 + solve(i+1,j,s1,s2);
            int replace = 1 + solve(i+1,j+1,s1,s2);

            return dp[i][j] = min({insert,del,replace});
        }
    }
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        dp.assign(m+1,vector<int>(n+1,-1));
        return solve(0,0,word1,word2);
    }
};
