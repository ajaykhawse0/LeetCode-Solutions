class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {  
        int n = s1.size();

        vector<vector<string>>ans;
        vector<string>curr(2);

        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]){
                if(!curr[0].empty()){
                    ans.push_back(curr);
                }
                curr = vector<string>(2);

                continue;
            }
            else{
                curr[0] += s1[i];
                curr[1] += s2[i];
            }
        }
        if(!curr[0].empty()){
                    ans.push_back(curr);
                }
    return ans;}
};