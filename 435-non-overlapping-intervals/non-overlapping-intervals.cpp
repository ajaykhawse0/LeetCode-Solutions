class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count =0;
        auto cmp = [&](
            const vector<int>&a,
            const vector<int>&b
        ){
         return a[1]<b[1];
        };

        sort(intervals.begin(),intervals.end(),cmp);
        int prevEnd  =  intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(prevEnd>intervals[i][0]){
                count++;//interval marked for removal
            }
            else{
                prevEnd =  intervals[i][1];
            }
        }
    return count;}
};