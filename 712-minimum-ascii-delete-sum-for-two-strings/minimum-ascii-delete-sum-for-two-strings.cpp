class Solution {
public:
int n,m;
vector<vector<int>>memo;
int lcsSolve(int i,int j,string &s1,string &s2){
    if(i==n || j==m)return 0;
    if(memo[i][j]!=-1)return memo[i][j];
     int sum;
    if(s1[i]==s2[j]){
        //take
        sum = s1[i]+lcsSolve(i+1,j+1,s1,s2);
    }
    else{
        //skip one from s1 or s2

        sum = max({lcsSolve(i+1,j,s1,s2),lcsSolve(i,j+1,s1,s2)});
    }
      return  memo[i][j]=sum;
}
    int minimumDeleteSum(string s1, string s2) {
     n=s1.size();
     m=s2.size();
     memo.assign(n,vector<int>(m,-1));
     int x = lcsSolve(0,0,s1,s2);
    //  cout<<x;
     int total=0;
     for(char c:s1)total+=c;
     for(char c:s2)total+=c;
    //  cout<<total;
     return total-2*x;
       
    }
};