class Solution {
public:
    int maxProduct(int n) {
      int mx = INT_MIN;
      int sMX = INT_MIN;
      while(n>0){
        int d = n%10;
        if(d>mx){
            sMX = mx;
            mx = d;
        }
        else if(d>sMX){
            sMX = d;
        }
        n/=10;
      }  
    return mx*sMX;}
};