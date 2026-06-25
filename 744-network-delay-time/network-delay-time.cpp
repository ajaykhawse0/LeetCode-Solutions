class Solution {
public:
 typedef pair<int,int>P;
//times renamed to edges
    int networkDelayTime(vector<vector<int>>& edges, int V, int k) {
        //simple dijktras

         vector<vector<P>>adj(V+1);

         for(auto&edge:edges){
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];//weight

            adj[u].push_back({v,time});
         } 
         
         priority_queue<P,vector<P>,greater<P>>minHeap;
         //k is our src

         vector<int>dist(V+1,INT_MAX);
         int src = k;

         dist[src] = 0 ;//starts from here

         minHeap.push({0,src});

         while(!minHeap.empty()){
            auto[distance,node] = minHeap.top();
            minHeap.pop();

            if(distance > dist[node]){
                continue;
                //means the lesser distance already foun
            }

            for(auto& it:adj[node]){
                int connectedNode  = it.first;
                int weight = it.second;

                if(distance + weight < dist[connectedNode]){
                    dist[connectedNode] = distance + weight;
                    minHeap.push({dist[connectedNode],connectedNode});
                }
            }
         }
 
        int ans  = 0 ;

        for(int i=1;i<=V;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }

            ans = max(ans,dist[i]);
        }


         
        
    return ans;}
};