class Solution {
public:
int countLexSmallest(string s){
    vector<int>freq(26,0);
    for(char c:s){
        freq[c-'a']++;
    }
    int ans =0;
    for(int i=0;i<26;i++){
        if(freq[i]>0){
            ans = freq[i];
            break;
        }
    }
return ans;}
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>ans;
        vector<int>freq;
        for(string&word:words){
            freq.push_back(countLexSmallest(word));
        }
        sort(freq.begin(),freq.end());
        int n = freq.size();


        for(string&q:queries){
            int qfreq=countLexSmallest(q);
            auto idx = upper_bound(freq.begin(),freq.end(),qfreq)-freq.begin();

            ans.push_back(n-idx);
            
        }
       
        
    return ans;}
};