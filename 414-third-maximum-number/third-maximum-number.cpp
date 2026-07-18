class Solution {
public:
    int thirdMax(vector<int>& nums) {
       
        long long maxFirst = LLONG_MIN;
        long long maxSecond = LLONG_MIN;
        long long maxThird = LLONG_MIN;

          for(int &x:nums){
            if(x==maxFirst ||x==maxSecond ||x==maxThird) continue;      
            if(x>maxFirst){
                maxThird = maxSecond;
                maxSecond = maxFirst;
                maxFirst  = x;
            }
            else if(x>maxSecond){
                maxThird = maxSecond;
                
                maxSecond  = x;
            }
            else if(x>maxThird){
                maxThird = x;
            }
        }
        if(maxThird==LLONG_MIN)return maxFirst;
    return maxThird;}
};