class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sort the intervals first for easy traversal

        sort(intervals.begin(),intervals.end(),[&](const vector<int>&a,const vector<int>&b){
        
           return a[1]<b[1];
        });
        // cout<<intervals[1][0]<<intervals[1][1];

        // then take the first interval as reference;
        int refStart = intervals[0][0];
        int refEnd = intervals[0][1];

        int overlappingInt = 0;
        int n = intervals.size();

        //now iterate over the intervals to find the overlapping ones
        for(int i=1;i<n;i++){
            // if the start of the interval is lesser than the end of reference Intrval
            //Then it is an overlapping one 
           if(intervals[i][0]<refEnd){
            overlappingInt++;
           }
           else{
            //otherwise change the reference
            refStart = intervals[i][0];
            refEnd = intervals[i][1];
           }
        }

        return overlappingInt;
    }
};