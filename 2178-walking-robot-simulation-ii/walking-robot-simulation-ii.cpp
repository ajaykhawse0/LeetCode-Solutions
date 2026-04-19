class Robot {
public:
vector<vector<int>> directions = {
    {1,0},//EAST
    {0,1},//NORTH
    {-1,0},//WEST
    {0,-1}//SOUTH
};

vector<string>dirNames = {"East", "North",  "West","South"};
 int width ,height;
 int x,y,peri,dir=0;

    Robot(int width, int height) {
       this->width = width;        
       this->height = height;
       x=0;
       y=0;
       peri=2*(height+width-2);//perimeter of rectangle;        
    }


    
    void step(int num) {

        num = num%peri;
        if(num==0)num=peri;

       while(num>0){
        int nx = x + directions[dir][0];
        int ny = y + directions[dir][1];
//out of bound condition
        if(nx < 0 || nx >= width || ny < 0  || ny >= height ){
            //turn counterclockwise or left

            dir = (dir+1)%4;

           nx = x + directions[dir][0];
           ny = y + directions[dir][1];
        }
        x=nx;
        y=ny;
        num--;
       }
        
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dirNames[dir];
        
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */