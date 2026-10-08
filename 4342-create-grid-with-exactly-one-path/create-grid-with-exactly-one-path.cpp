class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s(n,'#');
         vector<string>ans(m,s);
        ans[0] = string(n, '.');
        for(int i=1;i<m;i++){
    
            ans[i][n-1]='.';
        }
    return ans;}
};