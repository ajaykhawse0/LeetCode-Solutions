class Solution {
public:
    int numSplits(string s) {
        //count unique chars from start , end
        int n = s.size();
        vector<int>pref(n),suff(n);

        unordered_map<char,int>mpp;

        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            pref[i] = mpp.size();
        }
        mpp.clear();
        for(int i=n-1;i>=0;i--){
            mpp[s[i]]++;
            suff[i] = mpp.size();
        }

        int ans= 0;

        for(int i=0;i<n-1;i++){
           if(pref[i]==suff[i+1])ans++;
        }
        return ans;
    }
};