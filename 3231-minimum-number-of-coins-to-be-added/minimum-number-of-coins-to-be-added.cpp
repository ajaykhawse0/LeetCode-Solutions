class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        //sort the coin to easily check if every value from[1,target] is obtainable

        sort(coins.begin(),coins.end());

        //without taking any coin the first miss will be 1

        int miss = 1;
        int i = 0;
        int added = 0;
        int n = coins.size();
        while(miss<=target){
            if(i<n && coins[i]<=miss){
                miss += coins[i];
                i++;
            }
            else{
                // if a coin is not obtained if it best to add it self to the set
                miss += miss;
                added++;//one coin is added

                //observation if we add an coin x to the array then it helps to form all the denominations from x to 2*x
            }
        } 
    return added;}
};