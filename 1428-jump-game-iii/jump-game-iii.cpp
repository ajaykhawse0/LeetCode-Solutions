class Solution {
public:
    int n ;
    bool dfs(vector<int>&arr,int curr,vector<int>&vis){
        if(arr[curr]==0)return true;
        if(vis[curr])return false;
        vis[curr]=1;

        int forwardMove=curr+arr[curr];
        int backwardMove=curr-arr[curr];
        if(forwardMove>=0 && forwardMove<n){
            if(dfs(arr,forwardMove, vis))return true;
        }
        if(backwardMove>=0 && backwardMove<n){
            if(dfs(arr,backwardMove, vis))return true;
        }
return false;
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
     
        // if(toReach==start)return true;
        vector<int>vis(n);
        return dfs(arr,start, vis);
    }
};