class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
       unordered_set<int>st(nums.begin(),nums.end());
       for(int i=0;i<32;i++){
        if(!st.count(1<<i))return 1<<i;
       }
    return 0;}
};