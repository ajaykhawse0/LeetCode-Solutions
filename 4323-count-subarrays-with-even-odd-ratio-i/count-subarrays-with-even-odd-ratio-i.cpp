class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int ans = 0;
         /*
         x/y <= a/b
         bx <= ay
         
         if(y!=0 && b!=0)
        */
        for(int i=0;i<n;i++){
            int odd = 0,even =0 ;
            for(int j=i;j<n;j++){
                if(nums[j]&1)odd++;
                else even++;

                if(odd!=0 && (1LL*b*even <= 1LL * a * odd))ans++;
            }
        }
 return ans;   }
};