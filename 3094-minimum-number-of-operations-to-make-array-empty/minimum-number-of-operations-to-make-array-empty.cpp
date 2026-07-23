class Solution {
public:
    int minOperations(vector<int>& nums) {
        //  sort(nums.begin(),nums.end());

         int n = nums.size();
         int cnt = 0;

         unordered_map<int,int>mpp;

         for(int &n : nums){
            mpp[n]++;
         }

         int i = 0;
         while(i<n){
            if(mpp.find(nums[i])!=mpp.end()){
                int freq  = mpp[nums[i]];
                if(mpp[nums[i]]==1)return -1;
                else if(mpp[nums[i]]==4){
                    cnt+=2;
                    mpp.erase(nums[i]);
                    // i+=4;
                }
                else if(mpp[nums[i]]==2){
                    cnt++;
                    mpp.erase(nums[i]);
                    // i+=2;

                }
                else if(mpp[nums[i]]>=3){
                    cnt+=1;
                    mpp[nums[i]]-=3;
                    // i+=3;
                }

            }
            i++;
         }
    return cnt;}
};