class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1(nums1.begin(),nums1.end());
        unordered_set<int>st2(nums2.begin(),nums2.end());

        vector<vector<int>>ans(2);

        for(int num : st1){
            if(!st2.count(num)){
                ans[0].push_back(num);
            }
        }
        for(int num : st2){
            if(!st1.count(num)){
                ans[1].push_back(num);
            }
        }
 return ans;   }
};