class Solution {
public:
    long long nCr(int n,int r){
       if(r<0 || r>n)return 0;
       if(r==0 || r==n)return 0;

       if(r>n-r){
        r=n-r;
       }
       long long ans = 1;

       for(int i=0;i<r;i++){
        ans *= (n-i);
        ans /= (i+1);
       }
    //    cout<<ans;

       return ans;
    }
    int numTrees(int n) {
        long long val = nCr(2*n,n);
        n = n+1;
        return val/n;
     }
};