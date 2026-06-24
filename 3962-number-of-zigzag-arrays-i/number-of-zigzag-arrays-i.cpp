/*
BRUTE FORCE

(MEMOIZATION + RECURSION)
//Time Complexity => O(N*M^2*2)


class Solution {
public:
int N,M;
int MOD = 1e9+7;

int memo[2001][2001][2];
    
    int solve(int i,int prevVal,bool increasing){

        if(i==N){
            return 1;
        }
        
        int result = 0;
        if(increasing){
           for(int nextVal = prevVal+1; nextVal <= M ; nextVal++ ){
            
         result = (result + solve(i+1,nextVal,false)) % MOD;

           }
        }
        else{
           for(int nextVal = 1 ; nextVal < prevVal ; nextVal++ ){
            
         result = (result + solve(i+1,nextVal,true)) % MOD;

           }
        }
return result;
    }
    int zigZagArrays(int n, int l, int r) {
        //key observation as we do not have to return the sequence
        //we can map [l,r] range to [1,r-l+1]
        //for ex l=4 , r=5 =>[1,2]
        //l=10 r=16 to [1,7]

        memset(memo,-1,sizeof(memo));

         N = n;
         M = r-l+1;
         
         int result = 0;

         for(int startVal=1;startVal<=M;startVal++){
            result = (result + solve(1,startVal,true)) % MOD;
            result = (result + solve(1,startVal,false)) % MOD;
         }

        return result;
    }
};
*/



/*
Time Limit Exceeded => O(N*M^2*2)
class Solution {
public:
int N,M;
int MOD = 1e9+7;

    int zigZagArrays(int n, int l, int r) {
        //key observation as we do not have to return the sequence
        //we can map [l,r] range to [1,r-l+1]
        //for ex l=4 , r=5 =>[1,2]
        //l=10 r=16 to [1,7]
        
        int dp[2001][2001][2];
        memset(dp,0,sizeof(dp));

         N = n;
         M = r-l+1;
         
         

         for(int i=1;i<=M;i++){
            dp[N][i][0] = 1;
            dp[N][i][1] = 1;
         }

         for(int i=N-1;i>=0;i--){

            for(int prevVal = 1;prevVal<=M;prevVal++){
                
                //increasing

                for(int nextVal = prevVal+1;nextVal <= M;nextVal++){
                    dp[i][prevVal][1] = (dp[i][prevVal][1] + dp[i+1][nextVal][0])%MOD;
                }
                for(int nextVal = 1;nextVal < prevVal;nextVal++){
                    dp[i][prevVal][0] = (dp[i][prevVal][0] + dp[i+1][nextVal][1])%MOD;
                }

            }

         }

         int result = 0;

         for(int startVal = 1 ; startVal <= M ; startVal++){

            result = (result + dp[1][startVal][0])%MOD;
            result = (result + dp[1][startVal][1])%MOD;
         }



        return result;
    }
};
*/
class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {

        int M = r - l + 1;

     static int dp[2001][2001][2];

        // Base case
        for (int val = 1; val <= M; val++) {
            dp[n][val][0] = 1;
            dp[n][val][1] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {

            vector<long long> pref0(M + 1, 0);
            vector<long long> pref1(M + 1, 0);

            for (int val = 1; val <= M; val++) {
                pref0[val] = (pref0[val - 1] + dp[i + 1][val][0]) % MOD;
                pref1[val] = (pref1[val - 1] + dp[i + 1][val][1]) % MOD;
            }

            for (int prevVal = 1; prevVal <= M; prevVal++) {

                // state 0:
                // next value must be < prevVal
                dp[i][prevVal][0] = pref1[prevVal - 1];

                // state 1:
                // next value must be >= prevVal
                dp[i][prevVal][1] =
                    (pref0[M] - pref0[prevVal] + MOD) % MOD;
            }
        }

        long long ans = 0;

        for (int startVal = 1; startVal <= M; startVal++) {

            ans = (ans + dp[1][startVal][0]) % MOD;
            ans = (ans + dp[1][startVal][1]) % MOD;
        }

        return (int)ans;
    }
};