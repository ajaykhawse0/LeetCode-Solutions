class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mpp;
        stringstream ss(s1);
        string word;
        while(ss>>word){
            mpp[word]++;
        }
         stringstream sss(s2);
        
        while(sss>>word){
            if(mpp.count(word)){
                mpp[word]=-1;
                
            }
            else{
                mpp[word]++;
            }
        }
        vector<string>ans;

        for(auto&it:mpp){
            if(it.second==1)ans.push_back(it.first);
        }
 return ans;   }
};