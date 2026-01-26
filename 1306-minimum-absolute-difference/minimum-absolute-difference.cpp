class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
       sort(arr.begin(),arr.end());
       int minAbsolute = INT_MAX;
       int n = arr.size();
       for(int i=n-2;i>=0;i--){
            minAbsolute = min(minAbsolute,arr[i+1]-arr[i]);
       }
       vector<vector<int>>ans;
       for(int i=1;i<n;i++){
         if((arr[i]-arr[i-1])==minAbsolute){
            ans.push_back({arr[i-1],arr[i]});
         }
       }

    return ans;}
};