class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        for (int i = 0; i < nums.size() - 1; i++) {

            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                nums.erase(nums.begin() + i);
            }
        }

        return nums.size();
    }
};