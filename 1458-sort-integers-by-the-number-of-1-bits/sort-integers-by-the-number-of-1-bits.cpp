class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>vec;
        for(auto&a:arr){
            int bits = __builtin_popcount(a);
            vec.push_back({a,bits});
         }
         sort(vec.begin(),vec.end(),[](const std::pair<int, int>& a, const std::pair<int, int>& b){
            if(a.second==b.second)return a.first<b.first;
            return a.second<b.second;
         });
        vector<int>ans;
         for(auto&it:vec){
            ans.push_back(it.first);
         }

      
        return ans;
    }
};