class Solution {
public:
    int majorityElement(vector<int>& nums) {
   //REv
   
    //1st approach
     //HashMap
    //  unordered_map<int,int>freq;
    //  int n = nums.size();
    //  for(int num:nums){
    //     freq[num]++;
    //     if(freq[num]>n/2)return num;

    //  }
    //  return -1;

    //2nd Approach Sorting
    // sort(nums.begin(),nums.end());
    // int n = nums.size();
    // return nums[n/2];

    //3rd Approach the majority element count using voting algo

    int cnt=0;
    int candidate=0;
    for(int & num:nums){
        if(cnt==0){
        candidate=num;}

        if(num==candidate){
            cnt++;
        }
        else{
        cnt--;
        }
    }


  
return candidate;}
};