class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        unordered_map<int,int>mpp;//label->times used
        priority_queue<pair<int,int>>pq;
        int n = values.size();

        for(int i=0;i<n;i++){
            pq.push({values[i],labels[i]});
            
        }
         int ans = 0;
        while(!pq.empty() && numWanted>0){
           auto[val,label] = pq.top();
           pq.pop();

           if(mpp[label]<useLimit){
            ans += val;
            mpp[label]++;
            numWanted--;
           }

        }
 return ans;   }
};