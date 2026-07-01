class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>freq(n,0);
        for(auto&r:roads){
            freq[r[0]]++;
            freq[r[1]]++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        long long ans = 0;
        int i = 0 ;
        int mul = n;
        while(i<n){
            
          ans += (long long)freq[i]*mul;
          i++;
          mul--;
        }
return ans;
    }
};