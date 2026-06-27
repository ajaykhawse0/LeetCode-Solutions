class Solution {
public:typedef long long ll;
    ll digitSum(int n){
        ll ans =0;
        while(n>0){
           ans += n%10;
           n/=10;
        }
        return ans;
    }
    ll squareSum(int n){
        ll ans =0;
        while(n>0){
            int val = n%10;
           ans += (val*val);
           n/=10;
        }
        return ans;
    }

    bool checkGoodInteger(int n) {

return ((squareSum(n)-digitSum(n)) >=50);

    }
};