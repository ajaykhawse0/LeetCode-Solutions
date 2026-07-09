class Solution {
public:
    bool patternMatch(string pat,string query){
        int i=0;
        int n = pat.length();
        for(char c : query){

            if(i<n && c==pat[i])i++;
            else if(c<'a')return false;
        }
        return i==n;
    } 
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>result;

        for(auto&query:queries){
            result.push_back(patternMatch(pattern,query));
        }
    return result;}
};