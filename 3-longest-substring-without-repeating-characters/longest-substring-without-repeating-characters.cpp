class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        int maxLen = 1;
        unordered_map<char,int>mpp;
        //sliding window
        int l=0;
        int r=0;
        int n = s.size();

        while(r<n){
            if(mpp.count(s[r])){
                l = max(l,mpp[s[r]]+1);
                mpp.erase(s[r]);
            }
            maxLen = max(maxLen,r-l+1);
            mpp[s[r]]=r;
            r++;     
        }
    return maxLen;    
    }
};