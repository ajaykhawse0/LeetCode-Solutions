// class Solution {
// public:vector<vector<vector<int>>>memo;
//         vector<int>factorDiv;
//         int n;

//     int solve(vector<vector<int>>& items,int budget,int idx,int taken){
//         if(idx>=n)return 0;

//         if(memo[idx][budget][taken]!=-1)return memo[idx][budget][taken];

//         int skip = solve(items,budget,idx+1,0);

//         int take = 0;

//         if(budget >= items[idx][1]){
//             if(taken){
//             take = 1 + solve(items,budget-items[idx][1],idx,taken);
//             }
//             else{
//                 take =  1 + factorDiv[idx] +
//                 solve(items,budget-items[idx][1],idx,1);
//             }
//         }
//     return memo[idx][budget][taken] = max(skip,take);}

//     int maximumSaleItems(vector<vector<int>>& items, int budget) {
//         n = items.size();

//         memo.assign(n+1,vector<vector<int>>(budget+1,vector<int>(2,-1)));

//         factorDiv.assign(n,0);

//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(i==j)continue;

//                 if(items[j][0]%items[i][0]==0){
//                     factorDiv[i]++;
//                 }

//             }
//         }

//         return solve(items,budget,0,0);
//     }
// };
class Solution {
public:
    vector<int> factorDiv;
    int n;

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();

        factorDiv.assign(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (items[j][0] % items[i][0] == 0) {
                    factorDiv[i]++;
                }
            }
        }

        // iterative version
        vector<int> next(budget + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            vector<int> curr0(budget + 1, 0); // with free copy
            vector<int> curr1(budget + 1, 0); // without free copy

            int bonus = factorDiv[i];
            int price = items[i][1];
            for (int b = 0; b <= budget; b++) {
                //skip the curr budget
                curr0[b] = next[b];
                curr1[b] = next[b];
                if (b >= price) {
                    curr1[b] = max(curr1[b],1+curr1[b-price]);
                    curr0[b] = max(curr0[b],1+bonus+curr1[b-price]);
                }
            }
            next = curr0;
        }

        return next[budget];
    }
};