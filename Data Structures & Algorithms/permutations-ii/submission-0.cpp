class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int index, vector<int> &nums){
        if(index == nums.size()){
            ans.push_back(nums);
            return ;
        }
        unordered_set<int> s;
        for(int i = index; i<nums.size(); i++){
            if(s.count(nums[i])){
                continue;
            }
            s.insert(nums[i]);
            swap(nums[i],nums[index]);
            backtrack(index+1,nums);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        backtrack(0,nums);
        return ans;
    }
};