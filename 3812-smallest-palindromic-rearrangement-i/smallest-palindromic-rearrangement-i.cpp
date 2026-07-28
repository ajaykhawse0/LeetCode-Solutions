class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        
        int n = s.size();
        int left = 0;
        int right = n-1;

        string ans(n,' ');

        for(int i=0;i<26;i++){
            while(freq[i]>=2){
                ans[left] = 'a' + i;
                ans[right] = 'a' + i;

                left++;
                right--;

                freq[i] -= 2;
                
            }
            if(freq[i]==1){
                ans[n/2] = 'a'+i;
            }

        }

return ans;
    }
};