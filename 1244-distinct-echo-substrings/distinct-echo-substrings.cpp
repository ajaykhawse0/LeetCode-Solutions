class Solution {
public://Brute Force Solution
    int distinctEchoSubstrings(string text) {
        unordered_set<string>st;

        int n = text.size();

        for(int i=0;i<n;i++){
            for(int len = 2;i+len<=n;len+=2){
        int half = len / 2;
        int mid = i + half;

                string s1 = text.substr(i,half);
                string s2 = text.substr(mid,half);
                

               if(s1==s2)st.insert(s1);
            }
        }
    return st.size();}
};