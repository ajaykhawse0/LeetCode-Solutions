class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
    //count sort
    int n = nums.size();
    int mx = *max_element(nums.begin(),nums.end());
    vector<int>count(mx+1,0);

    for(int num:nums){
        count[num]++;
    }
    int idx = 0;
    for(int val = 0; val <= mx ; val++){
         
         while(count[val]>0){
            nums[idx] = val;
            idx++;
            count[val]--;
         }
    }

    vector<vector<int>>ans;

    for(int i=0;i<n;i+=3){
        if(nums[i+2]-nums[i]>k)return {};
        else{
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
    }
return ans;
   }
};