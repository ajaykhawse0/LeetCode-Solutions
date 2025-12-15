class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {

        int n = prices.size();
        long long sum =1 ,period =1;
        for(int i=1;i<n;i++){
            prices[i]+1==prices[i-1]?period+=1:period=1;
            sum+=period;
        }
    return sum;}
};