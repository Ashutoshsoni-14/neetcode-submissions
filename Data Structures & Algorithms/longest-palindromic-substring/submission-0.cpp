class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int idx = 0;
        int size = 0;
        vector<vector<bool>> dp(n , vector<bool>(n , false));
        for(int len = 1 ; len <= n ; len++){
            for(int i = 0; i+len-1 < n; i++){
                int j = i+len-1;
                if(i == j){// len = 1 case 
                    dp[i][j] = true;
                }
                else if(i+1 == j){ // len = 2 case
                    dp[i][j] = (s[i] == s[j]);
                }
                else{ // generalised case 
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j]){
                    if(j-i+1 > size){
                        size = j-i+1;
                        idx = i;
                    }
                }
            }
        }
        return s.substr(idx , size);
    }
};
