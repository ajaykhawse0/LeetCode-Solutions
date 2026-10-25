class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
             unordered_map<string,int>mpp;

             for(string word:words1){
                mpp[word]++;
             }
             for(string word:words2){
                if(mpp[word]>1)continue;
                mpp[word]--;
             }

             int count = 0;

             for(auto it:mpp){
                if(it.second==0)count++;
             }
  return count;  }
};