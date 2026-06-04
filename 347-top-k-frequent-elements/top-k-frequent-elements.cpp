class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }

        priority_queue<pair<int,int>>pq;//maxHeap {freq,num};

        for(auto & it:freq){
            pq.push({it.second,it.first});
        }
        vector<int>ans(k);
        for(int i=0;i<k;i++){
            ans[i]=pq.top().second;
            pq.pop();
        }
    return ans;}
};