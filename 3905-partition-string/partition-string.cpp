class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string>st;

        string temp;

        vector<string>ans;
        for(char c:s){
            temp += c;
            if(!st.count(temp)){
                st.insert(temp);
                ans.push_back(temp);
                temp="";
            }
        }
        
    return ans;}
};