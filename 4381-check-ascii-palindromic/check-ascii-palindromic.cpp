class Solution {
public:
    bool isPalindromic(string s) {
      string str = "";
      for(char c:s){
        for(int i=7;i>=0;i--){
           int bit = (c >> i) & 1;
           str  += to_string(bit);
      }  
      }
      auto str1 = str;
      reverse(str1.begin(),str1.end());
      return str == str1;
    }
};