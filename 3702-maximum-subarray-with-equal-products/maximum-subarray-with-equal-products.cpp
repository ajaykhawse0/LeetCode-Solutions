class Solution {
public:
    int maxLength(vector<int>& nums) {
        //brute force;

        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
             long long prod = nums[i];
             long long Gcd = nums[i];
             long long Lcm = nums[i];
            for(int j=i+1;j<n;j++){
                  Gcd = gcd(Gcd,(long long)nums[j]);
                  Lcm = lcm(Lcm,(long long)nums[j]);
                  prod *= nums[j];
                 if(prod>25200){
                    break;
                 }
                  if(prod==Gcd*Lcm){
                    ans = max(ans,j-i+1);
                  }
            }
        }
 return ans;   }
};