class DSU {
    vector<int>rank,parent;
    public :
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);


    }

    int findUltPar(int node){
        if(node==parent[node])return node;

        return parent[node] =  findUltPar(parent[node]);
    }

    void UnionByRank(int u,int v){

        int PU = findUltPar(u);
        int PV = findUltPar(v);

        if(PU==PV)return;

        int rankU = rank[PU];
        int rankV = rank[PV];

        if(rankU<rankV){
            parent[PU]=PV;
            
        }
        else if(rankU>rankV){
            parent[PV]=PU;

        }
        else{
            parent[PV]=PU;
            rank[PU]++;
        }
    }
};

class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces=0;
         
         DSU ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;

                if(isConnected[i][j]==1){
                    ds.UnionByRank(i,j);
                }
                
            }
        }
        for(int i=0;i<n;i++){
            if(ds.findUltPar(i)==i){
                provinces++;
            }
        }
 return provinces;          }
};