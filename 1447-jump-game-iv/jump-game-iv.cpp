/*
class Solution {
public:
    int steps(int i,vector<int>&arr,unordered_map<int,vector<int>>&mpp,vector<int>&visited){
        if(i>=arr.size()-1)return 0;
        
        if(visited[i])return INT_MAX;
         visited[i]=1;
        int ans = INT_MAX;
        vector<int>&temp = mpp[arr[i]];

        int next = steps(i+1,arr,mpp,visited);

        if(next!=INT_MAX){
            ans = min(ans,1+next);
        }

        if(i>=1){
            next = steps(i-1,arr,mpp,visited);
            if(next!=INT_MAX){
                ans = min(ans,1+next);
            }

        }

        for(int j=0;j<temp.size();j++){
            if(temp[j]!=i){
                next = steps(temp[j],arr,mpp,visited);
                if(next!=INT_MAX){
                    ans = min(ans,1+next);
                }
            }
        }

        
        
    visited[i]=0;

    return ans;


    }
    int minJumps(vector<int>& arr) {
     unordered_map<int,vector<int>>mpp;
     for(int i=0;i<arr.size();i++){
        mpp[arr[i]].push_back(i);
     }  
     vector<int>visited(arr.size(),0);
     return steps(0,arr,mpp,visited);
    }
};
*/
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1)return 0;
        vector<int>visited(n,0);
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }
        
        queue<int>q;

        q.push(0);//start
        //  visited[0]=1;
        int steps=0;
        while(!q.empty()){
            int size = q.size();
            for(int j=0;j<size;j++){
                int curr = q.front();
                q.pop();
                  if(curr==arr.size()-1)
                    return steps;
                visited[curr]=1;
                if(curr+1<n && !visited[curr+1]){
                    q.push(curr+1);
                    visited[curr+1]=1;
                }
                if(curr-1>=0 && !visited[curr-1]){
                    q.push(curr-1);
                    visited[curr-1]=1;
                }
                vector<int>temp=mpp[arr[curr]];
                for(int i=0;i<temp.size();i++){
                    if(!visited[temp[i]]){
                        q.push(temp[i]);
                        visited[temp[i]]=1;
                    }
                }
                mpp[arr[curr]].clear();


            }
            steps++;
        }

    return steps;}
};