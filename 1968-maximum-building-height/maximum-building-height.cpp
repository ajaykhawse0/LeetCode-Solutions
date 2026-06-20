class Solution {
public:
    int process(vector<vector<int>>& restrictions,int m){
        int maxHeight=0;
        for(int i=1;i<m;i++){
            int nextHeight = restrictions[i][1];
            int currHeight = restrictions[i-1][1];
            
            int nextPos = restrictions[i][0];
            int currPos = restrictions[i-1][0];
            //causing issue while R->L processing that is why using abs
            int distance = abs(nextPos-currPos);
            
            nextHeight = min(nextHeight,
            currHeight + distance
            );

            restrictions[i][1] = nextHeight;

            maxHeight = max(maxHeight,(nextHeight+currHeight+distance)/2);
        }
return maxHeight;
    }
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

       //dummy boundaries
       restrictions.push_back({1,0});
       restrictions.push_back({n,n-1});

       //sorting to preserve the order
       sort(restrictions.begin(),restrictions.end());

       //Lets see what rules say:
       //1. Height[building] should not be less than 0 (height>=0)
       //2. The height difference (height[building[i]]-height[building[i-1]]<=1)
       //3. Restrictions is a array that provide the the height cap on a building x.
       
       //Key OutComes
       //1. Height of [ith] building can be at max height[i-1]+1 or height[i+1]+1;
       //2. We have to process from Left->Right then from Right->Left;
       //3. Then to find the maxHeight We have to use a formula: ((height[i]+height[i+1])+(nextRescritedPos - currRestricedPos)/2);

       // Left -> Right
       process(restrictions,restrictions.size());

       reverse(restrictions.begin(),restrictions.end());

       // Right -> Left
       // return these result because we only get peak  or maxHeight when both side processing is done
      return process(restrictions,restrictions.size());


    }
};