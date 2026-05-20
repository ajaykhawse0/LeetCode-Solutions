class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k>=n){
            return *max_element(arr.begin(),arr.end());
        }
        int currentWinner = arr[0];
        int consecutiveWins = 0;

        for(int i=1 ; i<n ; i++){
            if(currentWinner > arr[i]){
             consecutiveWins++;
            }
            else if(arr[i]>currentWinner){
                currentWinner = arr[i];
                consecutiveWins=1;
            }
            if(consecutiveWins>=k)return currentWinner;
        }
    return currentWinner;}
};