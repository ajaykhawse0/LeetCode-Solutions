class Solution {
public:typedef pair<int,int> PP;
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
       int minD = INT_MAX;
        int ans = -1;
        for(int i=0;i<drones.size();i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int z = drones[i][2];

            int dist = abs(target[0]-x)+abs(target[1]-y);

            if(dist <= z){
                if(dist<minD){
                    minD=dist;
                    ans = i;
                }
            }
        }



       
return ans;    }
};