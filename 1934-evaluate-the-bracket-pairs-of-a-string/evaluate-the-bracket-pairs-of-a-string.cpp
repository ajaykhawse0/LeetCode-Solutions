class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        int n = s.length();

        for(auto&k:knowledge){
            mpp[k[0]]=k[1];
        }
        string ans="";
        string key="";
        bool open = false;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open = true;
            }
           else if(s[i]==')'){
                open = false;
                if(mpp.count(key)){
                    ans+=mpp[key];
                }
                else{
                    ans += '?';
                }
                key="";
            }
            else if(open){
                key+=s[i];
            }
            else{
                ans+=s[i];
            }
        }
return ans;
    }
};