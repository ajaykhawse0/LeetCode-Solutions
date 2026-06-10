class Solution {
public:typedef pair<int,int>P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P,vector<P>,greater<P>>pq;
        for(int num:nums2){
            pq.push({nums1[0]+num,0});
        }

        vector<vector<int>>ans;

        while(k-- && !pq.empty()){
            auto[sum,idx1]=pq.top();
            pq.pop();

            ans.push_back({nums1[idx1],sum-nums1[idx1]});

            if(idx1+1<nums1.size()){
                pq.push({sum-nums1[idx1]+nums1[idx1+1],idx1+1});
            }

            
        }


        return ans;
    }
};