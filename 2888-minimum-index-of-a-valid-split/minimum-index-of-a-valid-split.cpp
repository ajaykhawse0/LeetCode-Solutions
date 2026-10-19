class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        //boyer moore algo

        int majority = nums[0];
        int cnt = 0;

        for(int num:nums){
            if(num==majority)cnt++;
            else cnt--;
            if(cnt==0){
                majority = num;
                cnt=1;
            }
        }
/////////////////////////////////////////////////
        int majorityCnt = 0;
        for(int num:nums)if(num==majority)majorityCnt++;

         int n = nums.size();
         int currCount = 0;
        for(int i=0;i<n;i++){
          if(nums[i]==majority){
            currCount++;
          }
          if(currCount*2>(i+1) && (majorityCnt - currCount)*2>(n-i-1))return i;
        }

        return -1; 
    }
};