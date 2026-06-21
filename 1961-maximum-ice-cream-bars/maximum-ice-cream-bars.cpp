class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        //count sort;
        int maxCost = *max_element(costs.begin(),costs.end());
        vector<int>freqArr(maxCost+1,0);
        int ans = 0;
        for(int&cost:costs){
            freqArr[cost]++;
        }
        for(int cost=1;cost<=maxCost;cost++){

            int freq = freqArr[cost];

            if(freq==0)continue;

            int iceCreamBought = min(coins/cost,freq);

            if(iceCreamBought==0){
                break;
            }

            ans += iceCreamBought;

            coins -= iceCreamBought*cost;
             
        }
    return ans;}
};