class Solution {
public:
    int minimumDistance(vector<int>& nums) {
       unordered_map<int,vector<int>>mpp;
       int n = nums.size();
       for(int i=0;i<n;i++){
        mpp[nums[i]].push_back(i);
       } 
       int ans = INT_MAX;
       for(auto&it:mpp){
        vector<int>&temp=it.second;
        int m = temp.size();
        if(m>=3){
        for(int i=0;i<m-2;i++){
            int a = temp[i];
            int c = temp[i+2];
            int mini = 2*(abs(a-c));
            ans = min(ans,mini);
        }}
       }
    return ans==INT_MAX?-1:ans;}
};