class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort(intervals.begin(),intervals.end(),[&](const vector<int>&a,const vector<int>&b){
        //     if(a[0]<b[0])return true;
        //     return a[1]<b[1];
        // });
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        result.push_back({intervals[0][0],intervals[0][1]});

        int n = intervals.size();

        for(int i=1;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start>result.back()[1]){
                result.push_back({start,end});
            }
            else{
                result.back()[1]=max(end,result.back()[1]);
            }

        }        
    return result;}
};