class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //O(N) T.C. O(N)S.C

        unordered_map<int,int>freq;
        vector<int>ans;
        for(int n:nums){
            freq[n]++;
        }

        for(auto&it:freq){
            if(it.second==1){
                ans.push_back(it.first);
            }
            if(ans.size()==2)return ans;
        }
    return ans;}
};