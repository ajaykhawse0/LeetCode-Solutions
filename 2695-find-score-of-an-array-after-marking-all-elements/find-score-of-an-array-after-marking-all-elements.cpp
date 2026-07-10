class Solution {
public:typedef pair<int,int>P;
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        priority_queue<P,vector<P>,greater<P>>minHeap;
        vector<bool>mark(n,false);
        for(int i=0;i<n;i++){
            minHeap.push({nums[i],i});
        }
        while(!minHeap.empty()){
            auto[val,idx] = minHeap.top();
                minHeap.pop();
            if(mark[idx]){
                continue;
            }
            score += val;

            mark[idx] = true;

            if(idx-1 >= 0){
                mark[idx-1] = true;
            }
            if(idx+1 < n){
                mark[idx+1] = true;
            }
        }
 return score;   }
};