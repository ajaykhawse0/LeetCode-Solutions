class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0;
        int greater = 0;

        for(int a:nums){
            if(a<target){
                less++;
            }
            else if(a>target){
                greater++;
            }
        }

        vector<int>ans;
        int n = nums.size();
        for(int i = less;i<n-greater;i++){
            ans.push_back(i);
        }
    return ans;}
};