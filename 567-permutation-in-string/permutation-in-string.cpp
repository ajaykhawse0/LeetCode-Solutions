class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.length();
        if(n>s2.length())return false;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(char c:s1){
            freq1[c-'a']++;
        }

        for(int i=0;i<n;i++){
            freq2[s2[i]-'a']++;
        }

        if(isValidPer(freq1,freq2))return true;

        //now we will sliding window to check if permutation persist in any window 

        int i=0;
        int j=n;
        int m = s2.size();

        while(j<m){
            //shrink from left
            freq2[s2[i]-'a']--;
            //expand in right
            freq2[s2[j]-'a']++;

            if(isValidPer(freq1,freq2))return true;

            i++;
            j++;
        }

return false;
    }

    bool isValidPer(vector<int>&freq1,vector<int>&freq2){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i])return 0;
        }
        return 1;
    }
};