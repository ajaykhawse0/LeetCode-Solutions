class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        
        int close = nums[0];

        for(int num:nums){
            if(abs(num) < abs(close)){close=num;}
                
            else if(abs(num) == abs(close) && num>close){
                    close = num;
                }
                
            
        }
 return close;   }
};