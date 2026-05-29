class Solution {
public:
    bool isRobotBounded(string instructions) {
        char currDir = 'N';
        int x=0;
        int y=0;

        for(char c:instructions){
            if(c=='G'){
                y +=  (currDir == 'N')?1:0;
                y +=  (currDir == 'S')?-1:0;
                x +=  (currDir == 'E')?1:0;
                x +=  (currDir == 'W')?-1:0;
            }
            else {
                char instruction = c;
               
               
                if(currDir=='N'){
                    currDir = (instruction=='L')?'W':'E';
                }
               else if(currDir=='S'){
                    currDir = (instruction=='L')?'E':'W';
                }
               else if(currDir=='E'){
                    currDir = (instruction=='L')?'N':'S';
                }
               else if(currDir=='W'){
                    currDir = (instruction=='L')?'S':'N';
                }
            
            } 
                
            }

            if((x==0 && y==0) || currDir!='N')return true;

            return false;
        
    }
};