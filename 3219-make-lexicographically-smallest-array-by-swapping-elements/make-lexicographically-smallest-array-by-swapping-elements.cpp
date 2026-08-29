class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>sorted = nums;
        sort(sorted.begin(),end(sorted));
        int n = nums.size();
        unordered_map<int,int>groupMap;
        unordered_map<int,list<int>>groupValues;
        int group = 0;
        groupMap[sorted[0]] = group;
        groupValues[group].push_back(sorted[0]);
        for(int i=1;i<n;i++){
            if(abs(sorted[i]-sorted[i-1])>limit)group++;

        groupMap[sorted[i]] = group;
        groupValues[group].push_back(sorted[i]);

        }
        vector<int>ans;
        for(int num:nums){
           int currGrp = groupMap[num];
           ans.push_back(groupValues[currGrp].front());
           groupValues[currGrp].pop_front();
        }

   return ans; }
};