class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int maxFreq = 0;
        vector<int>freq(26,0);
        string ans ;
        for(char c:s){
            freq[c-'a']++;
            maxFreq = max(maxFreq,freq[c-'a']);
        }

        while(maxFreq>0){
            string temp;
            for(int i=0;i<26;i++){
               if(maxFreq==freq[i])temp += 'a'+i;
            }
            if(ans.empty()||ans.size()<temp.size()){
                ans = temp;
            }
            maxFreq--;
        }
 return ans;   }
};