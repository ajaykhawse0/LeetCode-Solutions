class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int>st(nums.begin(),nums.end());

        int i = lower;
        vector<vector<int>>ans;

        while(i<=upper){
            if(!st.count(i)){
            int start = i;
            while(!st.count(i) && i<=upper){
              i++;     
            }
            ans.push_back({start,i-1});
            }
            i++;

        }
        
   return ans; }
};