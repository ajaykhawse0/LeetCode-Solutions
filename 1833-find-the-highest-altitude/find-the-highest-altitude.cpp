class Solution {
public:
    int largestAltitude(vector<int>& gain) {
    int ans =0,curr=0;
    for(int g:gain){
        curr += g;
        if(curr>ans){
            ans = curr;
        }
    }      
    return ans;}
};