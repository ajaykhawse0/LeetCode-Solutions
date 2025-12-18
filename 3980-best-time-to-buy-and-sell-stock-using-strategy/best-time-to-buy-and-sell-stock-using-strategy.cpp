class Solution {
public:
typedef long long ll;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long actualProfit = 0;

        int n = prices.size();
        vector<ll>profit(n);

        for(int i=0;i<n;i++){
            profit[i] = (ll)(strategy[i]*prices[i]);
            actualProfit+=(strategy[i]*prices[i]);
        }
       
       //Sliding Window
       int i = 0,j=0;
       int half = k/2;

       ll originalWindowProfit=0,modifiedfWindowProfit=0;

       ll maxGain=0;


       while(j<n){
            
            originalWindowProfit += profit[j];

                //Only Second half will contribute
            if(j - i + 1 > half){
                modifiedfWindowProfit += prices[j];

            }
            
            // if window is exceeding then we have to shrink it
            if(j - i + 1 > k){
                
                originalWindowProfit -= profit[i];
                modifiedfWindowProfit -= prices[i+half];//because only half contributes
                 i++;
            }

            if ( j - i + 1 == k){

                maxGain= max(maxGain,modifiedfWindowProfit-originalWindowProfit);
            }
      j++; }

return actualProfit+maxGain; }
};