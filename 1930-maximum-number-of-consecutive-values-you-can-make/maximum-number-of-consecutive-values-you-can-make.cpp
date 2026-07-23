class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        //observation : if we have coins of value (X) and next val is (V) we can make values till x+v
        
        sort(coins.begin(),coins.end());
        int currVal = 0;
        for(int coin:coins){
            if(currVal+1 >= coin ){
                currVal = max(currVal,currVal+coin); 
            }
        }
    return currVal+1;}//0 is counted
};