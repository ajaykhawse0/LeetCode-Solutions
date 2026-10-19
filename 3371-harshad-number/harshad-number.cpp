class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int n) {
        int a =  n;

        int sum = 0;
        while(a>0){
            sum += a%10;
            a /= 10;
        }
    return (n%sum==0)?sum:-1;}
};