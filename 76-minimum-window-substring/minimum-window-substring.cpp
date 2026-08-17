class Solution {
public: bool possible(vector<int>&freq1,vector<int>&freq2){
    for(int i=0;i<58;i++){
        if(freq2[i]<freq1[i])return false;
    }
    return true;
}
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m>n)return "";
        vector<int>freq1(58,0);
        vector<int>freq2(58,0);
        
        for(auto&c:t){
            freq1[c-'A']++;
        }
        
        int l = 0;
        int r = 0;
        int bestStart = 0;
        int bestLen = INT_MAX;

        while(r<n){
            freq2[s[r]-'A']++;
            while(possible(freq1,freq2)){
                if( r-l+1<bestLen){
                    bestLen = r-l+1;
                    bestStart = l;
                }
                freq2[s[l]-'A']--;
                l++;
            }
            r++;
        }
        if(bestLen == INT_MAX)return "";
        
 return s.substr(bestStart,bestLen);    }
};