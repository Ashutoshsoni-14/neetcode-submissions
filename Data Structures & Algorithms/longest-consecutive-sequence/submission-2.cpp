class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        sort(nums.begin(),nums.end());
        int lcs = 0;
        int currLCS = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] == nums[i-1]+1){
                currLCS++;
            }
            else if(nums[i] == nums[i-1]){
                lcs = max(lcs , currLCS);
                continue;
            }
            else{
                currLCS = 1;
            }
            lcs = max(lcs , currLCS);
        }
        return lcs;
    }
};
