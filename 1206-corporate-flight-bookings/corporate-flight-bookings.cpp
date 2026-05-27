class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);
        int m = bookings.size();
        for(int i=0;i<m;i++){

            for(int j=bookings[i][0]-1;j<bookings[i][1];j++){
                ans[j]+=bookings[i][2];
            }
        }
 return ans;   }
};