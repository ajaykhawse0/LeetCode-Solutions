class Solution {
public: using ll  = long long;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        //prefSum on the fly
        long long sum = 0;
        //variable of ans
        long long ans = LLONG_MIN;
        //an hashmap that will have key and its corresponding prefSum
        unordered_map<long long,long long>mpp;
         
        //we can answer only if nums[i]+k or nums[i]-k is there in the array 
        for(int num:nums){
            sum += num;
        
            long long key = num + k;

            if(mpp.count(key)){
                ans = max(ans,sum - mpp[key]);
            }

            key = num - k;

            if(mpp.count(key)){
                ans = max(ans,sum-mpp[key]);
            }
            
            //time to store the curr nums[i]
            key = num;
            if(!mpp.count(key)){
                mpp[key] = sum - num;
            }
            else{
                //try to store minimum sum to get maximum answer
                if((sum - num) < mpp[key]){
                     mpp[key] = sum - num;
                }
            }
        }
 return ans == LLONG_MIN ? 0 : ans;   }
};