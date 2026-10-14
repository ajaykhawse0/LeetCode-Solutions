class Solution {
public:
    vector<vector<int>>jumps={
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {0,3,9},
        {},
        {0,1,7},
        {2,6},
        {1,3},
        {2,4}
    };
    const int MOD = 1e9+7;
    int knightDialer(int n) {
        if(n<1)return 0;
        //for every n there are only 10 digits at max
        vector<vector<long long>>moves(n,vector<long long>(10,0));

         //for n = 1 as array is 0 index 0 represemt 1 and similarly n-1 => n        
        for(int i=0;i<10;i++){
            moves[0][i] = 1;
        }

        for(int i=1;i<n;i++){

            for(int j=0;j<10;j++){

                for(int k = 0;k<jumps[j].size();
                k++){
                    moves[i][j] += moves[i-1][jumps[j][k]];
                }

                moves[i][j] = moves[i][j]%MOD;
            }
        }

        int ans = 0;

        for(int x:moves[n-1]){
            ans = (ans + x)%MOD;
        }
        ans = ans%MOD;

        return ans;
    }
};