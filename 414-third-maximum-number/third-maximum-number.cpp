class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        priority_queue<int>pq(st.begin(),st.end());

        if(pq.size()<3)return pq.top();
        int i=0;
        while(!pq.empty()){
            i++;
            if(i==3)return pq.top();
            pq.pop();
        }
        return -1;
    }
};