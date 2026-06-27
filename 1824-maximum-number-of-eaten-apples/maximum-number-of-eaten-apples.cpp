class Solution {
public:
    typedef pair<int,int>P;
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int i = 0;
        int n = apples.size();

        int ans = 0;

        priority_queue<P,vector<P>,greater<P>>pq;



        while(i<n || !pq.empty()){
            if(i<n && apples[i]>0){
                pq.push({i+days[i]-1,apples[i]});
            }

            while(!pq.empty() && pq.top().first < i){
                pq.pop();
            }

            if(!pq.empty()){
                P it = pq.top();
                pq.pop();
                ans++;
                if(it.second-1>0){
                    pq.push({it.first,it.second-1});
                }
            }
            i++;

        }
    return ans;}
};