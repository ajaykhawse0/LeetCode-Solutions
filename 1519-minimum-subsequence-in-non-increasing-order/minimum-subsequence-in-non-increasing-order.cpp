class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
       long long sum = accumulate(nums.begin(),nums.end(),0LL);
       priority_queue<pair<int,int>>pq;
       int n = nums.size();
       for(int i=0;i<n;i++){
        pq.push({nums[i],i});
       } 

       long long remaining=0;
       vector<pair<int,int>>vec;

       while(!pq.empty()){
        sum -= pq.top().first;
        remaining += pq.top().first;


        vec.push_back({pq.top().second,pq.top().first});
        pq.pop();
        if(remaining > sum){
            break;
        }
       }

      vector<int>ans;

      for(auto&[idx,val]:vec){
        ans.push_back(val);
      }
    return ans;}
};