class Solution {
public:int n;
    void solve(vector<int>&temp,vector<int>&nums,set<vector<int>>&st,int idx){
        if(idx>=n){
            if(temp.size()>=2){
                st.insert(temp);
            }

            return;
        }

        if(temp.empty()||temp.back()<=nums[idx]){
            temp.push_back(nums[idx]);
            solve(temp,nums,st,idx+1);
            temp.pop_back();

        }
            solve(temp,nums,st,idx+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
         n = nums.size();
        
         vector<int>temp;
         set<vector<int>>st;

         solve(temp,nums,st,0);
         vector<vector<int>>result(st.begin(),st.end());
         return result;
    }
};