class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        stringstream ss(s);
        string finall="";
        string word;
        while(ss>>word){
            finall = " "+word + finall;  
        }
        s = move(finall);
        return s.substr(1); 
    }
};