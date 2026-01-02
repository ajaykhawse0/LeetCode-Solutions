// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {
//         int n = nums.size()/2;

//         unordered_map<int,int>mpp;
//         for(int &num : nums){
//             mpp[num]++;
            
//             if(mpp[num]==n)return num;
//         }
// return -1;    }
// };
//PigeonHole Principle :- it states that if you have more items ("pigeons") than containers ("pigeonholes"), at least one container must hold more than one item.
class Solution{
    public:
    int repeatedNTimes(vector<int>&nums){

        int n = nums.size();

        for(int i=0;i<n-2;i++){
            if(nums[i]==nums[i+1]||nums[i]==nums[i+2]){
                return nums[i];
            }
        }
        
  return nums[n-1];  }
};