class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n; // this is the edge case : if k > n

        // this is the trick : 
        reverse(nums.begin() , nums.end());
        reverse(nums.begin() , nums.begin()+k);
        reverse(nums.begin()+k , nums.end());
        return ;
    }
};