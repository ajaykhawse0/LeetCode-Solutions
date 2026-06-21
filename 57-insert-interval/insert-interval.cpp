class Solution {
public:
    vector<vector<int>>mergeIntervals(vector<vector<int>>& intervals){
        sort(intervals.begin(),intervals.end());

        vector<vector<int>>results;
        results.push_back(intervals[0]);
        int n = intervals.size();
        
        for(int i=1;i<n;i++){
            if(results.back()[1]<intervals[i][0]){
                results.push_back(intervals[i]);
            }
            else{
                results.back()[1] = max(results.back()[1],intervals[i][1]);
            }
        }
return results;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //intervals is alreday sorted so we will just simulate
        //We have two options 
        //1.Simply insert the newInterval at the very end And then call the helper
        //mergeInterval function that will take care of the overalpping ones 
        
        // intervals.push_back(newInterval);

        // return mergeIntervals(intervals);


        //2.Optimal approach that is to handle overlapping interval on the go;

        int n = intervals.size();
        vector<vector<int>>result;
        int i = 0;
        //traverse till the end of an interval is lesser than the newInterval
        while(i<n && intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }
        //now it is a case where there can be overlapping or a place for newInterval;

        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);

            i++;
        }

        result.push_back(newInterval);
        
        //insert remaining interval

        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }

return result;

    }
};