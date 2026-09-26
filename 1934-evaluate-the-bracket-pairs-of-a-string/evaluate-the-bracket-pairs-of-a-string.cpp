class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        for(auto k:knowledge){
            mpp[k[0]]=k[1];
        }
        bool andar = false;
        string key="";
        string ans="";
        for(char c:s){
            if(c=='('){
                andar = true;
                key="";
            }
            else if(c==')'){
                andar = false;
                ans += mpp.count(key)?mpp[key]:"?";
            }
            else if(andar)key+=c;
            else ans+=c;
        }
 return ans;   }
};