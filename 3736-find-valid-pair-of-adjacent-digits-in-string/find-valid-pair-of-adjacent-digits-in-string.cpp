class Solution {
public:
    string findValidPair(string s) {
        vector<int>freq(10,0);
        for(char c:s){
            freq[c-'0']++;
        }

        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1])continue;

            if(freq[s[i]-'0']==s[i]-'0' && freq[s[i+1]-'0']==s[i+1]-'0'){
                return {s[i],s[i+1]};
            }
        }
    return "";}
};