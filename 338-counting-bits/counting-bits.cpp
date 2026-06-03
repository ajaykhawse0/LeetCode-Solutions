class Solution {
public:
int noOfSetBits(int n){
    int ans  =0;
    for(int i=0;i<32;i++){
        ans += n&1;
        n = n>>1;
    }
return ans;}
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        ans[0]=0;
        for(int i=1;i<=n;i++){
          ans[i]=noOfSetBits(i);
        }
    return ans;}
};