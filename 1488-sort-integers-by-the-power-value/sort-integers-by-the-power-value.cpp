class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>arr;
        for(int i=lo;i<=hi;i++){
            int num = i;
            int power = 0;
            while(num!=1){
                if(num%2==0){
                    num/=2;
                }
                else{
                   num = 3*num+1; 
                }
                power++;
            }
            arr.push_back({power,i});
        }
        sort(arr.begin(),arr.end());

        return arr[k-1].second;
    }
};