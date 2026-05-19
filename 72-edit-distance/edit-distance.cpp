class Solution {
public:
    int m ,n;
    vector<vector<int>>dp;

int solve(int i,int j,string word1,string word2){
    if(i<0)return j+1;
    if(j<0)return i+1;

    if(dp[i][j]!=-1)return dp[i][j];

    if(word1[i]==word2[j]){
        return dp[i][j]=solve(i-1,j-1,word1,word2);
    }

    int insert = solve(i,j-1,word1,word2);
    int deleteChar = solve(i-1,j,word1,word2);
    int replace = solve(i-1,j-1,word1,word2);

    return dp[i][j]=1+min({insert,deleteChar,replace});
}

    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();

        dp.assign(m,vector<int>(n,-1));

        return solve(m-1,n-1,word1,word2);

        
    }
};