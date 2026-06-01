class Solution {
public:
int f(vector<int>&arr){
    int maxVal = *max_element(arr.begin(),arr.end());  
    int minVal = *min_element(arr.begin(),arr.end());  

    return (maxVal-minVal);
}
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
       int n = arr2.size();
       vector<int>sum1(n,0),sum2(n,0),diff1(n,0),diff2(n,0);
       
       for(int i=0;i<n;i++){
        sum1[i]=arr1[i]+arr2[i]+i;
        diff1[i]=arr1[i]-arr2[i]+i;
        sum2[i]=arr1[i]+arr2[i]-i;
        diff2[i]=arr1[i]-arr2[i]-i;
       }

       return max({f(sum1),f(sum2),f(diff1),f(diff2)});
    }
    
};