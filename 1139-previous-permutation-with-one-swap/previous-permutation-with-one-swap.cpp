class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int i=n-1;

        while(i>0 && arr[i-1]<=arr[i]){
    
                i--;
            
        }
        if(i==0)return arr;
        int pos = i;
        for(int j = i;j<n;j++){
            if(arr[j]<arr[i-1] && arr[j]>arr[pos]){
                pos=j;
            }
        }
swap(arr[pos],arr[i-1]);
    return arr;}
};