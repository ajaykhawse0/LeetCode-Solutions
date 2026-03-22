class Solution {
public:
vector<int>bfs(vector<vector<pair<int,int>>>&adj,int V){
    vector<int>dist(V,-1);
    queue<pair<int,int>>q;
    q.push({0,-1});//(node,color)
    dist[0]=0;
    vector<vector<bool>> vis(V,vector<bool>(2,false));
    int dis=1;

    vis[0][0]=true;
    vis[0][1]=true;

    while(!q.empty()){
        int size = q.size();

        for(int i=0;i<size;i++){
            auto[node,prevColor]=q.front();
            q.pop();

            for(auto it : adj[node]){
                auto[adnode,color]=it;

                if(!vis[adnode][color] && color!=prevColor){
                    q.push({adnode,color});
                    if(dist[adnode]==-1){
                        dist[adnode]=dis;
                    }
                    vis[adnode][color]=true;
                }
            }
        }
   dis++; }
return dist;
}
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<redEdges.size();i++){
            adj[redEdges[i][0]].push_back({redEdges[i][1],0});
        }
        for(int i=0;i<blueEdges.size();i++){
            adj[blueEdges[i][0]].push_back({blueEdges[i][1],1});
        }

        return bfs(adj,n);//unweighted graph

    }
};