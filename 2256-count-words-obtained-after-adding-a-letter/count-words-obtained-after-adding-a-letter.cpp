class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string>st;

        for(string s:startWords){
            sort(s.begin(),s.end());
            st.insert(s);
        }
        int ans = 0;

        for(string & t:targetWords){
            sort(t.begin(),t.end());
            for(int i=0;i<t.size();i++){
                string s = t.substr(0,i) + t.substr(i+1);
                if(st.count(s)){
                    ans++;
                    break;
                }
            }
        }
    return ans;}
};