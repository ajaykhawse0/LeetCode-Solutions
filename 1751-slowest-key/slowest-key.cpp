class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int>freq(26,0);
        freq[keysPressed[0]-'a'] = releaseTimes[0]-0;

        for(int i=1;i<keysPressed.length();i++){
            freq[keysPressed[i]-'a'] = max(freq[keysPressed[i]-'a'],releaseTimes[i]-releaseTimes[i-1]);
        }
        
        int mx = INT_MIN;
        char c;

        for(int i=0;i<26;i++){
            if(freq[i]>=mx){
                mx = freq[i];
                c = 'a'+i;
            }
        }
   return c; }

};