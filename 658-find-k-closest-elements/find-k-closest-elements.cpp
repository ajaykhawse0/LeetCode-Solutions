class Solution {
public:using P  = pair<int,int>;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<P,vector<P>,greater<P>>pq;
        for(int a:arr){
            pq.push({abs(a-x),a});
        }
        vector<int>ans;

        while(k--&&!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
 return  ans;  }
};