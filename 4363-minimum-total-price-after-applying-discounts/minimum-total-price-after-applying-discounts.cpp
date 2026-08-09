class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());

        int n = prices.size();
        int m = discounts.size();

        int i = n-1;
        int j = m-1;

        double ans = 0.0;

        while(i>=0 && j>=0){
            ans += (double)(prices[i]*(100-discounts[j]))/100;
             i--;
            j--;
        }
        while(i>=0 ){
            ans += (double)(prices[i]);
             i--;
            
        }
    return ans;}
};