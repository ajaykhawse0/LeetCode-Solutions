class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string,int>mpp;
        int mx=0;
        for(auto&response:responses){
            unordered_set<string>st;
            for(auto&res:response){
                if(st.count(res))continue;
                st.insert(res);
                mpp[res]++;
                mx = max(mx,mpp[res]);
            }}

            string ans ;
            for(auto&[s,freq]:mpp){
                if(freq==mx){
                    if(ans.empty()||s<ans){
                        ans=s;
                    }
                }
            }

    return ans;}
};