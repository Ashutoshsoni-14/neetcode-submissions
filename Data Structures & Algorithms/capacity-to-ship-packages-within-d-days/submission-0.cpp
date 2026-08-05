class Solution {
public:
    bool isPossible(vector<int> &weights , int cap , int days){
        int d = 0;
        int sum = 0;
        for(int w : weights){
            sum += w;
            if(sum > cap){
                d++;
                sum = w;
            }
        }
        return d+1 <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low < high){
            int mid = low + (high-low)/2;
            if(isPossible(weights, mid, days)) high = mid;
            else low = mid+1;
        }
        return low;
    }
};