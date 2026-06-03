class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        int n = s.size();
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            //first char val
            int first = s[i-1]-'0';
            //second letter numeric val 
            int second = stoi(s.substr(i-2,2));

            if(first>=1 && first<=9){
                dp[i]+=dp[i-1];
            } 
            if(second>=10 && second<=26){
                dp[i]+=dp[i-2];
            } 
            
            
            

        }
    return dp[n];}
};