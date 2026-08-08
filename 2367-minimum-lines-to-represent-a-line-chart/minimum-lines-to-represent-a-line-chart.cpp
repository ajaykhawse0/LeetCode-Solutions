class Solution {
public:typedef long long ll;
    int minimumLines(vector<vector<int>>& stockPrices) {
        /*Slope Equation(Formula)
        y2-y1/x2-x1;
         */
        int n = stockPrices.size();
        if(n<=1)return 0;
        sort(stockPrices.begin(),stockPrices.end());
        int lines = 1;
        for(int i=1;i<n-1;i++){

            ll x1 = stockPrices[i-1][0];
            ll y1 = stockPrices[i-1][1];
            
            ll x2 = stockPrices[i][0];
            ll y2 = stockPrices[i][1];
           
            ll x3 = stockPrices[i+1][0];
            ll y3 = stockPrices[i+1][1];

            ll dx1 = (x2-x1);
            ll dx2 = (x3-x2);

            ll dy1 = (y2-y1);
            ll dy2 = (y3-y2);
            /*
            dy1/dx1 == dy2/dx2 
            
            dy1 * dx2 == dy2*dx1
            */

            if(dy1*dx2 != dy2*dx1)lines++;
           
        }
    return lines;}
};