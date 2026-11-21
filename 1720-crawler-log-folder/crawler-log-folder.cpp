class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string>st;

        for(string log:logs){
            if(log=="./")continue;
            if(log=="../"){
               if(!st.empty()) st.pop_back();
            }
            else{
                st.push_back(log);
            }
            
        }
    return st.size();}
};