class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int>freq(26,0);
        vector<int>tarCount(26,0);

        for(char c:s){
            freq[c-'a']++;
        }
        for(char c:target){
            tarCount[c-'a']++;
        }
        
        int tCnt = INT_MAX;

        char c = 'a';

        

        for(int num:tarCount){
            if(num!=0){
               tCnt = min(tCnt,freq[c-'a']/num);
            }
            c++;
        }

return tCnt;

        
    }
};