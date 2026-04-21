class Solution {
public:
int revNum(int n){
    int rev = 0;

    while(n>0){
        int d = n%10;
        n/=10;
        rev = (rev*10)+d;
    }
    return rev;
}
    int mirrorDistance(int n) {
        
        int rev = revNum(n);

        return abs(rev-n);
    }
};