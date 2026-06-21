class Solution {
public:
    double power(double x , long long n){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 1.0/power(x , -n);
        }
        double half = power(x , n/2);

        double res;

        if(n%2 == 0){
            res = half * half;
        }
        else{
            res = half * half * x;
        }
        return res;
    }
    double myPow(double x, int n) {
        if(n == 0 || x == 1){
            return 1;
        }
        return power(x ,n);
    }
};
