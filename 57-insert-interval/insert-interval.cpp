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
        
        intervals.push_back(newInterval);

        return mergeIntervals(intervals);


        //2.Optimal approach that is to handle overlapping interval on the go;
    }
};