class Solution {
public:
 int n;
bool isSorted(vector<int>nums){
    
    for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])return false;
    }
    return true;
}
int minPairPos(vector<int>nums){
    int pos=0;
    int minSum = INT_MAX;
    for(int i=1;i<nums.size();i++){
        if((nums[i]+nums[i-1])<minSum){
            minSum = nums[i]+nums[i-1];
            pos = i;
        }

   }
    return pos;
}

void mergePairs(vector<int>&nums,int pos){
nums[pos-1]+=nums[pos];
nums.erase(nums.begin()+pos);

}
    int minimumPairRemoval(vector<int>& nums) {
     
        int operation = 0;

         
        while(!isSorted(nums)){
            mergePairs(nums,minPairPos(nums));
            operation++;
        } 
         

      
       return operation; 
    }
};