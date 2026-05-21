class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
       

        vector<int>freq(24,0);
         int count=0;
 //similar to count pair with sum k but with a mod

        for(int&h:hours){
            int rem = h%24;
            int need = (24-rem)%24;
            count += freq[need];
            freq[rem]++; 
        }
    return count;}

    
};