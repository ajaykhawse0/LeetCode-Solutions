class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int str2Len =  str2.length();
        int idx = 0;

        for(char& c : str1){
            if(idx==str2Len)return true;
            if(((str2[idx]-c)+26)%26 <= 1)idx++;
        }
    return idx==str2Len;}
};