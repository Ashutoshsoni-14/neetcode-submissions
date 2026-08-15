class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(int left, int right, string &s) {

        if(left >= right)
            return true;

        if(dp[left][right] != -1)
            return dp[left][right];

        if(s[left] != s[right])
            return dp[left][right] = false;

        return dp[left][right] =
            isPalindrome(left + 1, right - 1, s);
    }

    int countSubstrings(string s) {
        int n = s.length();

        int count = 0;

        dp.assign(n + 1, vector<int>(n + 1, -1));

        for(int i = 0 ;i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(i,j,s)) count++;
            }
        }
        return count;
    }
};
