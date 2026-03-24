class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
    
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
               for(char ch='a';ch<='z';ch++){
                char prev =(i>0)?s[i-1]:0;
                char next =(i<n-1)?s[i+1]:1 ;

                if(prev!=ch && next!=ch){s[i]=ch;break;}

               
                }
            }
        }
    return s;}
};