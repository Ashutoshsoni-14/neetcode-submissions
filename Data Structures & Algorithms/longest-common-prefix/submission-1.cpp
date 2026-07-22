class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());
        string s = strs[0];
        string t = strs[strs.size() - 1];
        int len = min(s.length() , t.length());
        string ans = "";
        for(int i = 0 ;i<len ;i++){
            if(s[i] == t[i]) ans += s[i];
            else{
                break;
            }
        }
        return ans;
    }
};