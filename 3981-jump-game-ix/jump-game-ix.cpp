class Solution {
public:
class DSU{
  vector<int>parent,size,maxArr;
    public:
    DSU(int n,vector<int>&nums){
        parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);
        size.resize(n+1,1);
        maxArr=nums;
    }

    int findUltPar(int u){
        if(parent[u]==u)return u;
        return parent[u]=findUltPar(parent[u]);
    }

    void unionBySize(int u,int v){
        int parU = findUltPar(u);
        int parV = findUltPar(v);
         
        if(parU==parV)return;
        int sizeU=size[parU];
        int sizeV=size[parV];
        if(sizeU<sizeV){
            swap(parU,parV);
        }
        size[parU]+=sizeV;
        parent[parV]=parU;

        maxArr[parU]=max(maxArr[parV],maxArr[parU]);



    }
    int returnMaxVal(int i){
        return maxArr[findUltPar(i)];
    }


};
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefMax(n);//by rule Jump to index j where j < i is allowed only if nums[j] > nums[i].
        vector<int>suffMin(n);//by rule Jump to index j where j > i is allowed only if nums[j] < nums[i].

        prefMax[0]=nums[0];
        suffMin[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            prefMax[i]=max(prefMax[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffMin[i]=min(suffMin[i+1],nums[i]);
        }

        DSU dsu(n,nums);

        for(int i=0;i<n-1;i++){
            if(prefMax[i]>suffMin[i+1]){
                dsu.unionBySize(i,i+1);
            }

        }

        vector<int>ans(n);

        for(int i=0;i<n;i++){
            ans[i]=dsu.returnMaxVal(i);
        }

return ans;
    }

};