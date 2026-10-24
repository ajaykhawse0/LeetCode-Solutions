class Solution {
public:
    string sortSentence(string s) {
        string ans;

        stringstream ss(s);

        string word;

        vector<string>result(10,"");
        while(ss>>word){
            int pos = word.back()-'0';

            word.pop_back();

            result[pos] = word;
        }

        for(int i=0;i<10;i++){
            if(result[i]!=""){

            ans += result[i];
            ans += " ";}
        }
        ans.pop_back();
 return ans;   }
};