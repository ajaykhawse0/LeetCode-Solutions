class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }

        // priority_queue<pair<int,int>>pq;//maxHeap {freq,num};
        set<pair<int,int>>st;

        for(auto & it:freq){
            // pq.push({it.second,it.first});
            st.insert({it.second,it.first});
            if(st.size()>k)st.erase(st.begin());
        }
        vector<int>ans;
        // vector<int>ans(k);
        // for(int i=0;i<k;i++){
        //     ans[i]=pq.top().second;
        //     pq.pop();
        // }
        for(auto&it:st){
            ans.push_back(it.second);
            
        }
        reverse(ans.begin(),ans.end());
    return ans;}
};