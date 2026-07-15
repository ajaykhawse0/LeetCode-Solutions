class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(int a:arr){
            mpp[a]++;
        }
        unordered_set<int>st;
        for(auto&it:mpp){
            if(st.count(it.second))return false;
            st.insert(it.second);
        }
 return true;   }
};