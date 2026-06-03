class Solution {
public:
    int characterReplacement(string s, int k) {
          vector<int>freq(26,0);

        //khandani template of sliding window
          int left =0;
          int right=0;
          int n = s.size();
          int maxCount=0;

          while(right<n){
            char c = s[right];
            freq[c-'A']++;
            maxCount =  max(maxCount,freq[c-'A']);

            if(right-left+1-maxCount > k){
                freq[s[left]-'A']--;
                left++;
            }
            right++;
          }
return n-left;
    }
};