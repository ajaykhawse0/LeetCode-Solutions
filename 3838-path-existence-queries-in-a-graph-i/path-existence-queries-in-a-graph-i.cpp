class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans(queries.size(),false);
        vector<int>root(n);
        root[0] = 0;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                root[i] = root[i-1];
            }
            else{
                root[i] = i;
            }
        }

        for(int i=0;i<queries.size();i++){
            if(root[queries[i][0]] == root[queries[i][1]]){
                ans[i] = true;
            }
        }
   return ans; }
};