class Solution {
public:
    string truncateSentence(string s, int k) {
        string t = "";
        stringstream ss(s);
        string word;
        while(ss>>word && k--){
        (k>0) ? t += word + " ":t += word;
        }
        return t;
    }
};