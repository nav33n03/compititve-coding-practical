class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(int i = 0; i < batteries.size(); i++){
            sum += batteries[i];
        }
        long long l = 1;
        long long r = sum / n;
        long long ans = 0;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if(check(n, batteries, mid)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
    bool check(int n, vector<int>& batteries, long long mid){
        long long req = n * mid;
        long long x = 0;
        for(int b : batteries){
            x += min((long long)b, mid);
        }
        if(x >= req){
            return true;
        }
        return false;
    }
};
