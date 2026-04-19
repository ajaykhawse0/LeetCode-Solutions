class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
            map<pair<int,int>,int>mpp;

            for(auto&a : obstacles){
                pair<int,int>p = make_pair(a[0],a[1]);
                mpp[p]++;
            }
              
            char dir = 'N';
            int x = 0,y=0;

            int maxD = INT_MIN;

            for(int i=0;i<commands.size();i++){
                if(commands[i] == -1){
                    //turn right

                    if(dir == 'N')dir='E';
                    else if(dir == 'E')dir='S';
                    else if(dir == 'S')dir='W';
                    else dir='N';
                    
                }
                else if(commands[i] == -2){
                    //left

                    if(dir == 'N')dir='W';
                    else if(dir == 'W')dir='S';
                    else if(dir == 'S')dir='E';
                    else dir='N';
                }
                else{
                    int steps = commands[i];

                    if(dir=='N'){
                        for(int j=0;j<steps;j++){
                            if(mpp.count({x,y+1})) break;
                            y++;
                        }
                    }
                  else if(dir=='E'){
                        for(int j=0;j<steps;j++){
                            if(mpp.count({x+1,y})) break;
                            x++;
                        }
                    }
                   else if(dir=='S'){
                        for(int j=0;j<steps;j++){
                            if(mpp.count({x,y-1})) break;
                            y--;
                        }
                    }
                    else if(dir=='W'){
                        for(int j=0;j<steps;j++){
                            if(mpp.count({x-1,y})) break;
                            x--;
                        }
                    }


                }
          maxD = max(maxD,x*x + y*y);  }

    return maxD;}
};