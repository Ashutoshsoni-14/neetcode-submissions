class Solution {
public:
    bool canEat(vector<int> &piles , int k , int h){
        int hr = 0;
        for(int p : piles){
            hr += p/k;
            if(p%k != 0) hr++;
        } 
        return hr <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low < high){
            int mid = low+(high - low)/2;
            if(canEat(piles , mid , h)) high = mid;
            else low = mid+1;
        }
        return low ;
    }
};
