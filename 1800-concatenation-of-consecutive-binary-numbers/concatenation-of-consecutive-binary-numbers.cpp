class Solution {
public:
int MOD=1e9+7;

    int concatenatedBinary(int n) {
      int length=0;
    unsigned long ans=0; // used long as int can not hold the big value that 2^31-1
      for(int i=1;i<=n;i++){
        if( (i&(i-1)) ==0)length++;
        ans=((ans<<length)|i)%MOD;
      }        
    return ans;}
};