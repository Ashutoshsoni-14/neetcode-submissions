class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recPermute(nums,0,ans);
        return ans;
    }
    void recPermute(vector<int> &nums , int idx , vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back({nums});
            return ;
        }
        for(int i = idx ; i < nums.size() ;i++){
            swap(nums[i] , nums[idx]);
            recPermute(nums,idx+1,ans);
            swap(nums[i],nums[idx]);
        }
    }
};
