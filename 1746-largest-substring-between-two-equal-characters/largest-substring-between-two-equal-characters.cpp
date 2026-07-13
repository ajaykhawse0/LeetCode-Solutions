class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<pair<int,int>>freq(26,{-1,0});
 
            for(int i=0;i<s.size();i++){
                if(freq[s[i]-'a'].first==-1){
                    freq[s[i]-'a'].first = i;
                }
                freq[s[i]-'a'].second = i;

            } 
            int len = -1;
            for(int i=0;i<26;i++){
                if(freq[i].first==-1 || freq[i].first == freq[i].second )continue;

                len = max(len,freq[i].second-freq[i].first-1);
            }
  return len;  }
};