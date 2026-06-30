class Solution {
public:
    int numberOfSubstrings(string s) {
     //khisakti hue window(sliding window)

     int l = 0;
     int r = 0;
     int n = s.size();
     int freq[3]={0};
     int ans = 0;

     while(r<n){
       
       freq[s[r]-'a']++;

       while(freq[0]>=1 && freq[1]>=1 && freq[2]>=1){
            ans += n-r;
            freq[s[l]-'a']--;
            l++;
       }
       r++;
  

     }

    return ans;}
};