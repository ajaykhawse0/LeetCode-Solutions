class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        unordered_map<char,int>mpp;
        int l = 0;
        int r = 0;
        int n = s.size();
        int ans = 1;
        while(r<n){
            if(mpp.count(s[r])){
                l = max(l,mpp[s[r]]+1);
                mpp.erase(s[r]);
            }
            ans = max(ans,r-l+1);
            mpp[s[r]] = r;
            r++;

        }
    return ans;}
};