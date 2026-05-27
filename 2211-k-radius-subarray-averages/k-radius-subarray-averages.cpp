class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>prefSum(n);
        prefSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefSum[i]=nums[i]+prefSum[i-1];
        }
        vector<int>ans(n);
        int div = (2*k)+1;
        for(int i=0;i<n;i++){
        if(i-k < 0 || i+k > n-1 ){
            ans[i]=-1;
        }
        else{
          if(i-k==0){
            ans[i] = prefSum[i+k]/div;
          }
          else{
            ans[i] = (prefSum[i+k]-prefSum[i-k-1])/div;
          }
            
        }
        }
    return ans;    
    }
};