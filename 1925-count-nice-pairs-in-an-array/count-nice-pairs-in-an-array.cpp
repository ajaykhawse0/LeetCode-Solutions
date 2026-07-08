class Solution {
public:
    int rev (int n){
        int d = 0;
        while(n>0){
            d = d*10 + n%10;
            n/=10;
        }

        return d;
    }
    int MOD = 1e9+7;
    int countNicePairs(vector<int>& nums) {
        int MOD = 1e9+7;
        int n = nums.size();
        long long ans = 0;
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            int val = nums[i]-rev(nums[i]);
            ans = (ans+mpp[val])%MOD;  
            mpp[val]++;
        }
       
 return ans;   }
};