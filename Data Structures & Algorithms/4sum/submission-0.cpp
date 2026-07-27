class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if(i>0 && nums[i] == nums[i-1]){continue;}
            for(int j = i+1;j<n-2;j++){
            if(j!=i+1&&nums[j]==nums[j-1])continue;
            int k = j + 1;
            int a = n - 1;
            while(k<a){
                long long sum = nums[i];
                sum = sum + nums[j]+nums[k]+nums[a];
                if(sum < target){
                    k++;
                }
                else if(sum > target){
                    a--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k],nums[a]});
                    k++;a--;
                    while(k<a && nums[k] == nums[k-1]) k++;
                }
            }
            }

        }
        return ans;
    }
};

