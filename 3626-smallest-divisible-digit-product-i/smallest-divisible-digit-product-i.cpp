class Solution {
public:
    int digitMul(int n){
        int product = 1;
        while(n>0){
            product *= n%10;
            n /= 10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        int m = n+10;

        while(n<=m){
            int mul = digitMul(n);
            if(mul%t==0)return n;
            n++;
        }
    return -1;}
};