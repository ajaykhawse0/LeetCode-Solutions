class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        vector<int>broken(26,0);
        for(char c:brokenLetters){
            broken[c-'a']=1;
        }
          string word;
          int cnt=0;
        while( ss>>word){
            bool canType = true;
           for(char c:word){
            if(broken[c-'a']){
                canType=false;
                break;
            }
           }
           if(canType)cnt++;
        }
    return cnt;}
};