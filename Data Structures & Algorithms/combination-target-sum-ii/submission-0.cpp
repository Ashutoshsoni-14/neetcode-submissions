class Solution {
public:
    void solve(vector<int>& nums, int idx, int tar, vector<int>& v, vector<vector<int>>& ans){
        if(tar < 0) return ;

        if(tar == 0){
            ans.push_back(v);
            return ;
        }
        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            v.push_back(nums[i]); // Take
            solve(nums,i+1,tar-nums[i],v,ans); // Explore
            v.pop_back(); // Remove
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(nums,0,target,v,ans);
        return ans;
    }
};
