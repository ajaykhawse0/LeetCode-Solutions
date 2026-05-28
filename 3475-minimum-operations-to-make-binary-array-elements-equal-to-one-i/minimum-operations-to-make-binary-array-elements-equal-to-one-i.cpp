class Solution {
public:
void flip(vector<int>&nums,int i,int j){
    while(i<=j){
        nums[i]=(nums[i]==0?1:0);
    i++;}
    
}
    int minOperations(vector<int>& nums) {
      int cnt=0;
      int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0 && i+2<n){
                flip(nums,i,i+2);
                cnt++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
            return -1;
            }
        }
        
    return cnt;}
};