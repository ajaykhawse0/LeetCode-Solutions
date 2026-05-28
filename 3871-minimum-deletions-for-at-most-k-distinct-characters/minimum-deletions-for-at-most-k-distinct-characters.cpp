class Solution {
public:
    int minDeletion(string s, int k) {
        map<char,int>freq;
        for(char c:s){
            freq[c]++;
        }
        if(freq.size()<=k)return 0;

        vector<pair<char,int>>vec(freq.begin(),freq.end());

         sort(vec.begin(), vec.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second;
        });
        
        int z = freq.size()-k;

        int ans = 0;
        
        for(int i=0;i<z;i++){
            ans += vec[i].second;
        }

                    return ans;}
};