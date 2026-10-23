class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        //check for two evens
        bool first = false;
        bool second = false;

        for(int n:nums){
            if(n%2==0){
                if(first){
                    second = true;
                }
                first = true;
            }
            if(first && second)return true;
        }
  return first&&second;  }
};