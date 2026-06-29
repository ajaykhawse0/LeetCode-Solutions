class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        //brute force
//         sort(arr.begin(),arr.end());
//         int res = 1;

//         for(int i=1;i<arr.size();i++){
//             if(arr[i]>=res+1){
//                res++;
//             }
//         }
// return res;

//optimal

int n = arr.size();
vector<int>freq(n+1,0);

for(int i=0;i<n;i++){
    freq[min(arr[i],n)]++;
}

int res = 1;

for(int i=2;i<=n;i++){

    res = min(res+freq[i],i);

}
   
return res;

    }
};