class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        string res;
        int len = s.size();
        for(int i=0;i<len;i++){
          if(i>0 && (len-i)%3 == 0){
            res +='.';
          }
          res += s[i];
        } 
 return res;   }
};