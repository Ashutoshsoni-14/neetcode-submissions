class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int>& nums, int i, int tar, vector<int>& v, vector<vector<int>>& ans){
        if(i == nums.size() || tar < 0) return;

        if(tar == 0){
            if(s.find(v) == s.end()){
                ans.push_back(v);
                s.insert(v);
            }
        }

        v.push_back(nums[i]);// include
        solve(nums,i+1,tar-nums[i],v,ans); // single include call 
        solve(nums,i,tar-nums[i],v,ans); // multiple include call 

        v.pop_back(); // exclude
        solve(nums,i+1,tar,v,ans); // exclude-call
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans; // to store all combinations
        vector<int> v; // combinations 
        solve(nums,0,target,v,ans);
        return ans;
    }
};
