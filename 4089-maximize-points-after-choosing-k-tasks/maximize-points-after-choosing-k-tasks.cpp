class Solution {
public:typedef long long ll;
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        vector<vector<int>>combine(n,vector<int>(2));

        for(int i=0;i<n;i++){
            combine[i][0] = technique1[i];
            combine[i][1] = technique2[i];
        }
     

sort(combine.begin(), combine.end(), [](const vector<int>& a, const vector<int>& b) {
    return (a[0] - a[1]) > (b[0] - b[1]);   // descending
});
   
   ll res=0;
   for(int i=0;i<k;i++){
    res += combine[i][0];
   }

   for(int i=k;i<n;i++){
    res += max(combine[i][0],combine[i][1]);
   }
     
    return res;}
};