class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n==1)return 1;
        string s = "";
        int currCnt = 1;
        char currChar='\0';
        for(int i=0 ; i<n-1;i++){
          
           if(chars[i] == chars[i+1]){
            currCnt++;
            currChar = chars[i];
           }
           else{
            s+=currChar=='\0'?chars[i]:currChar;
            if(currCnt>1){
                s+=to_string(currCnt);
            }
            currCnt=1;
            currChar='\0';
           }
        }
        if(currChar!='\0'){
            s+=currChar;
            if(currCnt>1){
                s+=to_string(currCnt);
            }
        }
        if(chars[n-1]!=chars[n-2]){
            s += chars[n-1];
        }
        chars.resize(s.size());
        for(int i=0;i<s.size();i++){
            chars[i]=s[i];
        }
        
    return chars.size();}
};