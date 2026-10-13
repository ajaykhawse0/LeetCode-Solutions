class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = 0;
        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<int>>minHeap;

        for(int a:nums){
            maxHeap.push(abs(a));
            minHeap.push(abs(a));
        }

        int n = nums.size();

        for(int i=0;i<n;i++){
            if(i%2==0){
                sum += maxHeap.top()*maxHeap.top();
                maxHeap.pop();
            }else{
                sum -= minHeap.top()*minHeap.top();
                minHeap.pop();
        }
        }
  return sum;  }
};