class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int profit = 0;
        int buy = prices[0];
        for(int p : prices){
            if(p > buy){
                profit = max(profit , p - buy);
                maxProfit = maxProfit + profit;
                profit = 0;
                buy = p;
            }
            buy = min(buy , p);
        }
        return maxProfit ;
    }
};