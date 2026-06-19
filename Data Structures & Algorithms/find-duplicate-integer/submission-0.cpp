class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int n : nums){
            mp[n]++;
        }
        for(auto & it : mp){
            if(it.second > 1) return it.first;
        }
        return 0;
    }
};
