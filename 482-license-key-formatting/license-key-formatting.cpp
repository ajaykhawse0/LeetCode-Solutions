class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";

        int n = s.size()-1;
        while(n>=0){
            string temp="";
            while(temp.size()<k && n>=0){
                if(isalnum(s[n])){
                    if(islower(s[n])){
                    temp += toupper(s[n]);
                    }
                    else{
                        temp+=s[n];
                    }
                }
                n--;
            }
            
            ans += temp +'-';
          
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='-' && i<ans.size()){
            i++;
        }
 return ans.substr(i);   }
};