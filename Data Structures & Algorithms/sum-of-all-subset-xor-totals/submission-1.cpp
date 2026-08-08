class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1<<n;
        int ans = 0;
        for(int num = 0; num < subsets; num++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                if(num & (1<<i)){
                    sum ^= nums[i];
                }
            }
            ans += sum;
        }
        return ans;
    }
};