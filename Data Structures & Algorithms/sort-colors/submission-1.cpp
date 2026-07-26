class Solution {
public:
    void sortColors(vector<int>& nums) {
        // DNF 
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        // mid se high wala part unsorted hai -
        // if it get sorted loop terminates 
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
                // we don't do mid++ here - 
                // bcz we don't know after swap with high - what is come here 0 or 1
            }
        }
    }
};