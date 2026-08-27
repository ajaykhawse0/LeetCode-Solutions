class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        string ans = "";
        vector<int>freq(26,0);
        int n = s.size();
        for(char c:s){
            freq[c-'a']++;
        }

        for(int i=0;i<n;i++){
            for(int j=target[i]-'a'+1;j<26;j++){
                if(freq[j]>0){
                    string curr = target.substr(0,i);
                    curr += char('a'+j);
                    freq[j]--;

                    for(int k=0;k<26;k++){
                        curr += string(freq[k],char('a'+k));
                    }

                    if(ans.empty()||curr<ans){
                        ans = curr;
                    }

                    freq[j]++;
                }

            }
            if(freq[target[i]-'a']==0)break ;
            freq[target[i]-'a']--;
        }
 return ans;   }
};