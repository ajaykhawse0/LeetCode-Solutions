class Solution {
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        vector<int>dp(n,0);
        int MOD = 1e9+7;
        // for 7 & 9 there are possibility of 4 letters
        int addition = 0;
        for(int i=0;i<n;i++){
            
            if(pressedKeys[i]=='7' || pressedKeys[i]=='9')addition = 1;
            
            else addition=0;

            for(int j=1 ;j <= 3+addition ;j++){

              if(i-j < 0){
                //j exceeds i;
                 dp[i] = (dp[i]+1)%MOD;
                       break;  
              }
              else if(pressedKeys[i-j]==pressedKeys[i]){
                     dp[i] = (dp[i]+dp[i-j])%MOD;
              }
              else{
                dp[i]=(dp[i]+dp[i-j])%MOD;
                break;
              }

            }
        }
    return dp[n-1];}
};