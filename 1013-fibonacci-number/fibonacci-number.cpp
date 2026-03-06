class Solution {
public:
    int fib(int n,int x=0) {
        if(n==0)return 0;
        if(n==1)return 1;

        return x+fib(n-1,x)+fib(n-2,x);

    }
};