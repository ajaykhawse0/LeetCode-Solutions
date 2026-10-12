class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        //count set bits and then form number from it

        long long MOD = 1e9+7;
        vector<int>cnt(31,0);
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = nums[i];
          for(int bit=0;bit<31;bit++){
            if(x&(1<<bit)){
                cnt[bit]++;
            }
          }
        }

        long long ans = 0;

        for(int i=0;i<k;i++){
            long long x = 0;

            for(int bit=0;bit<31;bit++){
                if(cnt[bit]>0){
                    x |=(1LL<<bit);
                    cnt[bit]--;
                }
            }

            ans = (ans + (1LL*x*x)%MOD)%MOD;
        }
   return ans; }
};