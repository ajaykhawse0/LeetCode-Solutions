class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>ans;

        for(string s:words){
            string token;
            stringstream ss(s);
            while(getline(ss,token,separator)){
               if(!token.empty()) ans.push_back(token);
            }
        }
 return ans;   }
};