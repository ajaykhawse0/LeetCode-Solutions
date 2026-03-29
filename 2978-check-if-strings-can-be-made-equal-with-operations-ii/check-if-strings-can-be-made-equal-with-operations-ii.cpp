class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();

        vector<int>Even(26,0);
        vector<int>Odd(26,0);

        for(int i=0;i<n;i++){
            if(i%2==0){
                Even[s1[i]-'a']++;
                Even[s2[i]-'a']--;
            }
            else{
                Odd[s1[i]-'a']++;
                Odd[s2[i]-'a']--;
            }
        }

        for(int i=0;i<26;i++){
            if(Even[i]!=0 || Odd[i]!=0)return false;
        }
 return true;   }
};