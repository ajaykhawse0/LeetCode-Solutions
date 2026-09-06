class Solution {
public:
    int m,n;
    vector<vector<long long>>memo;

    long long solve(int i,int j,string &s,string &t){
        if(j==n)return 1;//one subsequence is found
        if(i==m)return 0;//s is exhausted

        if(memo[i][j]!=-1){
            return memo[i][j];//all tried this path
        }

        long long ans = solve(i+1,j,s,t);//skip even if it is equal

        if(s[i]==t[j]){
            //take
            ans += solve(i+1,j+1,s,t);
        }

        return memo[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        m = s.size();
        n = t.size();

        memo.assign(m,vector<long long>(n,-1));

        return solve(0,0,s,t);
    }
};