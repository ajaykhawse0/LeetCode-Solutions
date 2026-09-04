class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size();
        int n = secondList.size();

        int i=0;
        int j=0;

        vector<vector<int>>ans;

        while(i<m && j<n){
            int intStart = max(firstList[i][0],secondList[j][0]);
            int intEnd = min(firstList[i][1],secondList[j][1]);

            if(intEnd>=intStart)ans.push_back({intStart,intEnd});

            if(firstList[i][1]<secondList[j][1])i++;
            else j++;

            
        }
    return ans;}
};