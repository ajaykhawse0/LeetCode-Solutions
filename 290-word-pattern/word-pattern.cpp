class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mpp;
        unordered_map<string,char>rev;
        int i=0;
        int n = pattern.size();
        string str;
        stringstream ss(s);

        while(ss>>str ){
            if(mpp.count(pattern[i])){
                if(mpp[pattern[i]]!=str)return false;
            }
            else{
                if(rev.count(str))return false;
                mpp[pattern[i]]=str;
                rev[str]=pattern[i];
            }
            i++;
        }
    return i==n;}
};