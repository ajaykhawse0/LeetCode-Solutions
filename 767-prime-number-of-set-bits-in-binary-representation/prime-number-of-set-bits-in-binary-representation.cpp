class Solution {
public:
bool isPrime(auto x){
    if(x<=1)return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
    int countPrimeSetBits(int left, int right) {
        int count=0;
        while(left<=right){
            auto bits = __builtin_popcount(left);
            if(isPrime(bits))count++;
            left++;
        }
 return count;   }
};