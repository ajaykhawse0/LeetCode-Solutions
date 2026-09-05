class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string,int>mpp;
        int ans = 0;
        for(string word:words){
            if(mpp.count(word)){
               ans += mpp[word];
               mpp[word]++;
            }
            else{
                string rev  = word;
                reverse(rev.begin(),rev.end());
                if(mpp.count(rev)){
                    ans += mpp[rev];
                    mpp[rev]++;
                }
                else{
                    mpp[word]++;
                }
            }
        }
 return ans;   }
};