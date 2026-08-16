class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
           sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
          return a[1]<b[1];
 
        });
        int overlapping = 0;
        int first = intervals[0][0];
        int second = intervals[0][1];
        int n = intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0] < second){
                overlapping++;}
             else{
        first = intervals[i][0];
        second = intervals[i][1];
             }   
        }
   return overlapping; }
};