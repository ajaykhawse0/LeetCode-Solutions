class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        unordered_map<int,priority_queue<int>>mpp;//limit -> values associated
         
         int n = value.size();
        for(int i=0;i<n;i++){
            mpp[limit[i]].push(value[i]);
        }

        long long ans = 0;

        for(auto&[limit,maxHeap]:mpp){
            for(int l = 0 ;l<limit && !maxHeap.empty();l++){
                ans  += (long long)maxHeap.top();
                maxHeap.pop();            }
        }
 return ans;   }
};