class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0;
        int j = s.length() -1 ;
        while(i<j){
            if(s[i] == ' ' && s[j] == ' '){
                i++;j--;continue;
            }
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            if(s[i] != s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
};
