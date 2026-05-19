class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st(nums1.begin(),nums1.end());
        for(int&n:nums2){
            if(st.count(n)){
                return n;
            }
        }
    return -1;}
};