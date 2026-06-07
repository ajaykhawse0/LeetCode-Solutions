class Solution {
public:typedef pair<int,int>P;
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<P,vector<P>,greater<P>>minHeap;

        long long sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){

            sum += nums[i];

            minHeap.push({nums[i],i});


        }
        vector<long long>ans;

        for(vector<int>&query:queries){
            sum -= nums[query[0]];
            nums[query[0]]=0;
            int k = query[1];
            while(!minHeap.empty() && k>0){
                if(nums[minHeap.top().second]>0){
                sum -= minHeap.top().first;
                nums[minHeap.top().second]=0;
                k--;}
                minHeap.pop();
            }

            ans.push_back(sum);

        }
    return ans;}
};