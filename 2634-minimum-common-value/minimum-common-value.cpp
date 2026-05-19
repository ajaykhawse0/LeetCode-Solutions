class Solution {
public:
    int getCommon(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(),m=arr2.size();
        int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]==arr2[j]){
            return arr1[i];
          }
        else if(arr1[i]<arr2[j])i++;
        else j++;
    }
   return -1; }
};