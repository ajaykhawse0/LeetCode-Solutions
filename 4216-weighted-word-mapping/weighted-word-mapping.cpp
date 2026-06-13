class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        vector<char>letters;

        for(int i=0;i<26;i++){
            letters.push_back(char('z'-i));
        }
        int j=0;
        string ans="";

        for(string& word:words){
            
            int sum=0;
            for(char&c:word){
                sum += weights[c-'a'];
            }
           
            sum%=26;
            // cout<<sum<<endl;

            ans += letters[sum];
        }
    return ans;}
};