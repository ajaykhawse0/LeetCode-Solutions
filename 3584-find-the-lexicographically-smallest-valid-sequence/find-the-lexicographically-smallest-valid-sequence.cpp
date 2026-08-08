class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int i = n-1;
        int j = m-1;

        vector<int>lastIdx(m,-1);//in word 1

        while(i>=0 && j>=0){
            if(word1[i]==word2[j]){
                lastIdx[j] = i;
                j--;
            }
            i--;
        }

        vector<int>ans;
        j=0;

        bool canSkip = true;

        for(int i = 0;i<n && j<m ;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(canSkip && (j==m-1 || i < lastIdx[j+1])){
                //If this is my first mismatch, and using this mismatch won't prevent me from matching the remaining characters, use this character.
                ans.push_back(i);
                j++;
                canSkip = false;
            }
        }
        ans.resize(m);
        if(j==m)return ans;
        return {} ; 
    }
};