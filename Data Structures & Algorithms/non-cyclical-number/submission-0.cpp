class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        int r = 0;
        int sum  = 0;
        while(n != 1){
            mp[n]++;
            if(mp[n] > 1){
                return false;
            }
            while(n>0){
                r = n%10;
                sum += (r*r);
                n = n/10;
            }
            n = sum;
            sum = 0;
        }
        return true;
    }
};
