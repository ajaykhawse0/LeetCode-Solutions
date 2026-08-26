class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int,int>inDegree;
        for(vector<int>&edge:edges){
            inDegree[edge[1]]++;
        }
        int ans = -1;
        int cnt = 0;
        int freq = INT_MAX;
        for(int i=0;i<n;i++){
            if(inDegree[i]<freq){
                ans = i;
                freq = inDegree[i];
                cnt = 0;
            }
            else if(inDegree[i]==freq){
                ans = i;
                freq = inDegree[i];
                cnt++;
            }
        }
        return cnt==0?ans : -1;
    }
};