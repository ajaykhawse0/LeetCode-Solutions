class Solution {
public:
    long long rev(int num){
        long long n = 0;
        while(num>0){
            n = (n*10)+num%10;
            num/=10;
        }
        return n;
    }
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum= 0;
        
        while(n>0){
            int val = n%10;
            if(val!=0){
            num = (num*10 + val);
            sum += val;}
            n/=10;
        }
        
        num = rev(num);
        
        return (num*sum);
    }
};