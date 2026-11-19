class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int min1=INT_MAX;
        int min2=INT_MAX;
        int min3=INT_MAX;
        int max1=0;
        int max2=0;
        int max3=0;


        for(int n:nums){
            if(n>=max1){
                max3=max2;
                max2=max1;
                max1=n;
            }
            else if(n>=max2){
                max3=max2;
                max2=n;
            }
            else if(n>=max3){
                
                max3=n;
            }
            if(n<=min1){
                min3=min2;
                min2=min1;
                min1=n;
            }
            else if(n<=min2){
                min3=min2;
                min2=n;
            }
            else if(n<=min3){
                
                min3=n;
            }
        }

    return min({max1-min3,max2-min2,max3-min1});}
};