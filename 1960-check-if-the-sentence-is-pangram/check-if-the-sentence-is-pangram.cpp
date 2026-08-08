class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.length();
        if(n<26)return false;
        vector<int>freq(26,0);

        for(char &c : sentence){
            freq[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]==0)return false;
        }

        return true;
    }
};