class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        /*slope between two points 
          slope = y2-y1/x2-x1
          there are three points=>(x1,y1)(x2,y2)(x3,y3)
          so there will be 2 slopes
          slope1 = y2-y1/x2-x1
          slope2 = y3-y2/x3-x2

          if slope1==slope2 then the points are in straight line else then are not

          means exp will become 
          y2-y1/x2-x1 != y3-y2/x3-x2
          which can be rewrittern as

          (y2-y1)*(x3-x2) != (y3-y2)(x2-x1)



    */
         int x1 =  points[0][0];
         int y1 =  points[0][1];
         
         int x2 =  points[1][0];
         int y2 =  points[1][1];
         
         int x3 =  points[2][0];
         int y3 =  points[2][1];


         return (y2-y1)*(x3-x2) != (y3-y2)*(x2-x1);

    }
};