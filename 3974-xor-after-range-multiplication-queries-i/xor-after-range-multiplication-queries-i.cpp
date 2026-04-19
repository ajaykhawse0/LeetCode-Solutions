class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        int MOD = 1e9+7;
        for(auto & q: queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            
            int idx = l;
            while(idx<=r){
                long long temp =  nums[idx];
                temp  =  ((temp*v)%MOD);
                nums[idx] = (int)temp;
                idx+=k;

            }

        }
        for(int&x:nums){
            ans^=x;
        }
   return ans; }
};