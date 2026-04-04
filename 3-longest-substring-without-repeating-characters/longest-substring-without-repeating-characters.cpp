class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        if(n==0 )return 0;
        if(n==1 )return 1;
        unordered_map<char,int>mpp;//char,idx
        int maxLen=0;
        int l=0;

        for(int r=0;r<n;r++){
            if(mpp.find(s[r])!=mpp.end()){
              
                if(mpp.find(s[r]) != mpp.end()) {
    l = max(l, mpp[s[r]] + 1);
}
               
                mpp.erase(s[r]);
            }
             maxLen=max(maxLen,r-l+1);
            mpp[s[r]]=r;
        }

    return maxLen;}
};