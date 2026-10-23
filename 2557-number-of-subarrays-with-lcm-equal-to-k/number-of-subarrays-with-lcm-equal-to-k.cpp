class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int res = 0;

        int n = nums.size();

        for(int i=0;i<n;i++){
            int curr = 1;

            for(int j=i;j<n;j++){
                if(k%nums[j]==0){
                   curr = lcm(curr,nums[j]);

                   res += curr==k;
                }
                else{
                    break;
                }
            }
        }
    return res;}
};