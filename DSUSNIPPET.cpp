// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Disjoint{
  vector<int>rank,parent,size;
  public:
  Disjoint(int n){
      rank.resize(n+1,0);
      parent.resize(n+1);
      size.resize(n+1);
      fill(size.begin(),size.end(),1);
      
      iota(parent.begin(),parent.end(),0);
  }
  
  int findUPar(int node){
      if(node==parent[node])return node;
      
      return parent[node] = findUPar(parent[node]);
  }
  
  void unionByRank(int u,int v){
      int ult_ParentU = findUPar(u);
      int ult_ParentV = findUPar(v);
      
      if(ult_ParentU==ult_ParentV)return;
      
      int rankPU = rank[ult_ParentU];
      int rankPV = rank[ult_ParentV];
      
      if(rankPU < rankPV){
          parent[ult_ParentU] = ult_ParentV;
      }
      else if(rankPV < rankPU){
          parent[ult_ParentV] = ult_ParentU;
      }
      
      else{
          //same rank
          parent[ult_ParentV] = ult_ParentU;
          rank[ult_ParentU]++;
      }
  }
  void unionBySize(int u,int v){
      int ult_ParentU = findUPar(u);
      int ult_ParentV = findUPar(v);
      
      if(ult_ParentU==ult_ParentV)return;
      
      int sizePU = size[ult_ParentU];
      int sizePV = size[ult_ParentV];
      
      if(sizePU < sizePV){
          parent[ult_ParentU] = ult_ParentV;
          size[ult_ParentV] += sizePU;
      }
      else if(sizePV < sizePU){
          parent[ult_ParentV] = ult_ParentU;
          size[ult_ParentU] += sizePV;
      }
      
      else{
          //same rank
          parent[ult_ParentV] = ult_ParentU;
        //   rank[ult_ParentU]++;
          size[ult_ParentU] += sizePV;
        
      }
  }
};

int main() {
    // Write C++ code here
    
    Disjoint ds(7);
    
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    cout<<ds.findUPar(2)<<endl;
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    cout<<ds.findUPar(7)<<endl;
    ds.unionBySize(5,6);
    (ds.findUPar(3)==ds.findUPar(7))?cout<<"\nsame":cout<<"\nnot same";
    ds.unionBySize(3,7);
    (ds.findUPar(3)==ds.findUPar(7))?cout<<"\nsame":cout<<"\nnot same";
 cout<<endl;
    
    cout<<ds.findUPar(2);
    

    return 0;
}
