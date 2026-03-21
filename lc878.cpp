class Solution {
public:
    #define mod 1000000007
    int nthMagicalNumber(int n, int a, int b) {
        int NumGcd = gcd(a, b);
        int lcm = (a / NumGcd) * b;
        long long left = min(a, b);
        long long right = 1ll * min(a, b) * n;
        long long ans = 0;
        while(left <= right){
            long long mid = (left + (right - left) / 2);
            long long num = (mid / a) + (mid / b) - (mid / lcm);
            if(num == n){
                ans = mid % mod;
            }else if(num < n){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return ans;
    }
    int gcd(int a, int b){
        if(b == 0){
            return a;
        }
        return gcd(b, a % b);
    }
};
