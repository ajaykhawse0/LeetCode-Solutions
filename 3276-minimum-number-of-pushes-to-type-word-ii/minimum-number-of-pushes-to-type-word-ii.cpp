class Solution {
public:
    int minimumPushes(string s) {
     //Greedy place all the letter which most freq early

     vector<int>freq(26,0);
     
     for(char c:s){
        freq[c-'a']++;
     }

     sort(freq.begin(),freq.end(),greater<int>());

     int ans  = 0;

     for(int i=0;i<26;i++){
        if(freq[i]!=0){
            ans  +=((i/8) + 1) * freq[i];
        }
        else break;
     }

    return ans;}
};