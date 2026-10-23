class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int>freq(26,0);

        for(auto w:words){
            for(char c:w){
                freq[c-'a']++;
            }
        }

        for(int i=0;i<26;i++){
             if((freq[i]%n)!=0)return false;
        }
    return true;}
};