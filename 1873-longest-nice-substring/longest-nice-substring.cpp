class Solution {
public:
    int n;
    string longestNiceSubstring(string s) {
        n = s.size();
        string res="";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                string str = s.substr(i, j - i + 1);

                if(isNiceSub(str)){
                  if(str.length()>res.length())res=str;
                }

            }
        }
  return res;  }

  bool isNiceSub(string s){
    unordered_set<char>st(s.begin(),s.end());
     
    for(int i=0;i<s.size();i++){
        if(!(st.count(tolower(s[i])) && st.count(toupper(s[i]))))return false;
    } 
    return true;
  }
};