class Solution {
public:  
    bool isAlphanumeric(string &s){
        for(char &c :s){
            if(!isalnum(c)){
                 if(c!='_'){
                    return false;
                 }
            }
        }
   return true; }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
        unordered_map<string,int>mpp={
            {"electronics",0}, 
            {"grocery", 1},
            {"pharmacy",2 },
            {"restaurant",3 }
            };

        

         vector<pair<int,string>> valid;
           int n = code.size();
          for(int i=0;i<n ;i++){
            if(code[i]=="")continue;
            if(!isAlphanumeric(code[i]))continue;
            if(mpp.count(businessLine[i])==0)continue;
            if(isActive[i]){
    valid.push_back({mpp[businessLine[i]],code[i]});
}          }
        sort(valid.begin(),valid.end());

        vector<string>ans;
        for(auto & it : valid){
            ans.push_back(it.second);
        }
        return ans;
    }
};