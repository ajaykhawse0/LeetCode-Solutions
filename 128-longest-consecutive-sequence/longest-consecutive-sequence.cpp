class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxLen = 0;

        for(int it:st){
            int prev = it-1;
            if(st.count(prev))continue;
            int next = it+1;
            int len = 1;

            while(st.count(next)){
                len++;
                next++;
            }
            maxLen = max(len,maxLen);

        }
        
    return maxLen;}
};