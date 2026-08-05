class Solution {
public:
    int findMin(vector<int> &nums) {
        // Linear Search . 
        // index of smallest element -> no. of times sorted array is rotated
        int minIndex = 0 ;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[minIndex]){
                minIndex = i;
            }
        }
        return nums[minIndex];
    }
};
