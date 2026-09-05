class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int ans = 0;
        
        int m = nums.size();
        int n = nums[0].size();
        for(int i=0;i<m;i++)
        sort(nums[i].begin(),nums[i].end(),greater<int>());
            for(int j=0;j<n;j++){
            int mx = 0;
        for(int i=0;i<m;i++){
              mx = max(mx,nums[i][j]);    
            }

            ans += mx;
            
        }

        return ans;
    }
};