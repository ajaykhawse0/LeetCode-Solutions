class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>mpp;

        for(int i=0;i<list1.size();i++){
            mpp[list1[i]]=i;
        }
        vector<string>ans;
        int minSum = INT_MAX;
        for(int i=0;i<list2.size();i++){
            if(mpp.count(list2[i])){
               int idxSum = i+mpp[list2[i]];
               if(idxSum<minSum){
                minSum = idxSum;
                ans = {};
                ans.push_back(list2[i]);
               }
               else if(idxSum==minSum){
                ans.push_back(list2[i]);
               }
            }
        }

    return ans;}
};