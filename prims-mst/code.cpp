typedef pair<int,int>P;
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
          
          vector<vector<pair<int,int>>> adj(V);
          
          for(auto&e:edges){
              int u = e[0];
              int v = e[1];
              int w = e[2];
              
             adj[u].push_back({v,w});
             adj[v].push_back({u,w});
              
              
          }
          
          priority_queue<P,vector<P>,greater<P>>minHeap;
          
          vector<bool>visited(V,false);
          
          minHeap.push({0,0});
          
          int mstWeight = 0;
          
          while(!minHeap.empty()){
              auto[wt,node] = minHeap.top();
              minHeap.pop();
              
              if(visited[node])continue;
              
              visited[node]=true;
              
              mstWeight += wt;
              for(auto&nei:adj[node]){
                  
                  int v = nei.first;
                  int w = nei.second;
                  
                  if(!visited[v]){
                      minHeap.push({w,v});
                  }
              }
          }
          
    return mstWeight;}
};
