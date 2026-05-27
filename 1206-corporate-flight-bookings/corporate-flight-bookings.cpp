class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        //difference Array technique

        vector<int>diff(n,0);

        for(vector<int>&booking:bookings){
            int l = booking[0]-1;
            int r = booking[1]-1;
            int seatsReserved = booking[2];
            
            diff[l] += seatsReserved;
            if(r+1<n){
            diff[r+1] -= seatsReserved;
            }

        }

        for(int i=1;i<n;i++){
            diff[i] += diff[i-1];
        }
    return diff;}
};