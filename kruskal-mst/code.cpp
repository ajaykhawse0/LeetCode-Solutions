class Disjoint{
    vector<int>parent,rank,size;
    
    public:
    
    Disjoint(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        // fill(size.begin(),size.end(),1);
        iota(parent.begin(),parent.end(),0);
    }
    
    int findUltPar(int node){
        if(node==parent[node]){
            return node;
        }
        
        return parent[node]=findUltPar(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int parentU = findUltPar(u);
        int parentV = findUltPar(v);
        
        if(parentU==parentV)return;
        
        int rankU = rank[parentU];
        int rankV = rank[parentV];
        
        if(rankU<rankV){
            parent[parentU]=parentV;
        }
        else if(rankV<rankU){
            parent[parentV]=parentU;
        }
        else{
            //both have same rank
            parent[parentU]=parentV;
            rank[parentU]++;
            
        }
    }
    void unionBySize(int u,int v){
        int parentU = findUltPar(u);
        int parentV = findUltPar(v);
        
        if(parentU==parentV)return;
        
        int sizeU = size[parentU];
        int sizeV = size[parentV];
        
        if(sizeU<sizeV){
            parent[parentU]=parentV;
            size[parentV]+=sizeU;
            
            
        }
        else {
            //if(sizeV<sizeU) or both has same size
            parent[parentV]=parentU;
            size[parentU]+=sizeV;
            
        }
        
    }
};
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        Disjoint ds(V);
        //  vector<pair<int,pair<int,int>>>adj;//wt,(u,v)
        int mstWeight = 0;
        sort(edges.begin(),edges.end(),[&](const vector<int>&a,const vector<int>&b){
            return a[2]<b[2];
        });
        for(auto&edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            
            if(ds.findUltPar(u)!=ds.findUltPar(v)){
                mstWeight+=wt;
                ds.unionBySize(u,v);
            }
            // adj.push_back({wt,{u,v}});
            
            
        }
        
        // sort(adj.begin(),adj.end());
        
        
        // for(auto&it:adj){
        //     int wt = it.first;
        //     int u = it.second.first;
        //     int v = it.second.second;
            
            
        // }
        
    return mstWeight;}
};












