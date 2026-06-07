class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n = queries.size();
        vector<int>ans(n,-1);
        priority_queue<int>maxHeap;
        // for(auto&q:queries){
        for(int i=0;i<n;i++){
            int dis = abs(queries[i][0])+abs(queries[i][1]);

            maxHeap.push(dis);

            if(maxHeap.size()>k){
                maxHeap.pop();
            }
            if(maxHeap.size()==k){
                ans[i]=maxHeap.top();
            }
        }
        
    return ans;}
};