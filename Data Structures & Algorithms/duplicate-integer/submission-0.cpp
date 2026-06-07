class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int n : nums){
            freq[n]++;
        }
        for(auto &it : freq){
            if(it.second >1) return true;
        }
        return false;
    }
};