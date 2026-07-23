class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        /*int main(){
    int n; cin>>n;
    set<int> s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                int x=i^j^k;
                if(!s.count(x)){
                    cout<<i<<"^"<<j<<"^"<<k<<"="<<x<<endl;
                    s.insert(x);
                }
            }
        }
    }
}*/

     int n = nums.size();
     if(n<3)return n;
     int bits = 0;
     int x = n;

     while(x){
        bits++;
        x = x>>1;//divide by 2;
     }
     return 1<<bits;
    }
};