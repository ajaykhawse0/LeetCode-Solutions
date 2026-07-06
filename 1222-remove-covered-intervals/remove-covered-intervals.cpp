class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
     sort(intervals.begin(),intervals.end(),[&](const vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
     });
    //  //print
    //  for(auto&interval:intervals){
    //     cout<<interval[0]<<" , "<<interval[1]<<endl;
    //  }   
      
      int n = intervals.size();
      pair<int,int>P=make_pair(intervals[0][0],intervals[0][1]);
      int cnt = 0;
      for(int i=1;i<n;i++){
        if(intervals[i][0]>=P.first && intervals[i][1] <= P.second){
            cnt++;
        }
        else{
            P = make_pair(intervals[i][0],intervals[i][1]);
        }
      }


    return n-cnt;}

};