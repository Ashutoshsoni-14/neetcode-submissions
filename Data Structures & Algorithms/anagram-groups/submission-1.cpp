class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans ;
        unordered_map<string , vector<string>> mp ; 
        for(string s : strs){
            string ors = s; // original string 
            sort(s.begin() , s.end());
            mp[s].push_back(ors);
        }
        for(auto & it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
