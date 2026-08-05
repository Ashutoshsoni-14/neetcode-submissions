class Solution {
public:
    int pivot(vector<int> &nums , int low , int high){
        while(low < high){
            while(low < high && nums[low] == nums[low+1]) low++;
            while(low < high && nums[high] == nums[high-1]) high--;
            int mid = low + (high - low)/2;
            if(nums[mid] < nums[high]) high = mid;
            else low = mid +1;
        }
        return high;
    }
    bool BinarySearch(vector<int>& nums,int low , int high, int target) {
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int p = pivot(nums, 0, n-1);
        if(BinarySearch(nums,0,p-1,target)) return true;
        return BinarySearch(nums,p,n-1,target);
        
    }
};