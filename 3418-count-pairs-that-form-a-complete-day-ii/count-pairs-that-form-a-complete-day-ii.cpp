class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int,int>freq;
        long long count=0;
 //similar to count pair with sum k but with a mod
 
        for(int&h:hours){
            int rem = h%24;
            int need = (24-rem)%24;
            count += freq[need];
            freq[rem]++; 
        }
    return count;}
};