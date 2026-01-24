class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //sort array on end time
        auto compare = [&](const vector<int>&a , const vector<int>&b){
            return a[1]<b[1];
        };
        sort(points.begin(),points.end(),compare);

        int prevEnd = points[0][1];
        int ans = 1;
        int n = points.size(); 
        for(int i=1;i<n;i++){
            //start>end means no overlapping
            if(points[i][0]>prevEnd){
                prevEnd=points[i][1];
                ans++;            }
        }
    return ans;}
};