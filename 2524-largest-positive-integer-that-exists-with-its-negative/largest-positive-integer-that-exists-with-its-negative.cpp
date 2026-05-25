class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int largest = INT_MIN;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
              mpp[nums[i]]++;
        }
        for(auto&[num,freq]:mpp){
            if(mpp.count(-num)){
                largest = max(largest,num);
            }
        }
 return largest==INT_MIN?-1:largest;   }
};