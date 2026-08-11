class Solution {
public:
    unordered_map<char,string> mp;
    vector<string> ans;
    void backtrack(int index, string &digits , string &current){
        if(index == digits.length()){
            ans.push_back(current);
            return;
        }
        char ch = digits[index];
        string str = mp[ch];

        for(int i = 0; i<str.length(); i++){
            current.push_back(str[i]);
            backtrack(index+1, digits, current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string current;
        backtrack(0,digits,current);
        return ans;
    }
};
