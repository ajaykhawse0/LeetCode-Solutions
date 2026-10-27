class Solution {
public:
int n ;
map<pair<vector<int>,int>,int>memo;
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,int idx){
        if(memo.count({needs,idx}))return memo[{needs,idx}];
        if(idx==special.size()){
            int res  = 0;

            for(int i=0;i<n;i++){
                res += price[i]*needs[i];
            } 

            return memo[{needs,idx}] = res;
        }


        //skip curr offer
        int skip = solve(price,special,needs,idx+1);
        
        //apply curr offer 

        bool valid = true;

        for(int i=0;i<n;i++){
            if(needs[i]<special[idx][i]){
                valid = false;
                break;
            }
        }

        int take = INT_MAX;

        if(valid){
            // vector<int>temp = needs;

            for(int i=0;i<n;i++){
                needs[i] -= special[idx][i];


            }

            take = special[idx][n] + solve(price,special,needs,idx);

           for(int i=0;i<n;i++){
                needs[i] += special[idx][i];


            }
        }

        return memo[{needs,idx}] = min(skip,take);

    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = price.size();
        memo.clear();
        return solve(price,special,needs,0);
        
    }
};