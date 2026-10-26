class Solution {
public:
    vector<int> constructArray(int n, int k) {
       int l = 1; 
       int r = k+1;
       int i = 0;
       
       vector<int>ans(n);
       while(i<k){
         ans[i] = l;
         i++;
         l++;
         ans[i]=r;
         i++;
         r--;
       } 

       if(l==r){
        ans[i] = l;
        i++;
       }

       while(i<n){
        ans[i] = i+1;
        i++;
       }
 return ans;   }
};