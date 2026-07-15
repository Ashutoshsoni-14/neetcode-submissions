class Solution {
public:
    // 3Sum is = i loop + (two sum in sorted array) 
    //T.C =  sort(nlogn) + n-(ith loop)*n-(j and k)th loop = O(n^2)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i = 0; i<n ;i++){
            // for not getting duplicates - 
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) j++;
                else if(sum > 0) k--;

                else{ // case: sum == 0
                    ans.push_back({nums[i] , nums[j] , nums[k]});
                    j++;
                    k--;
                    // for duplicates - 
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};
