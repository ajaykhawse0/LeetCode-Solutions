class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        pair<int,int>pos = {0,0};

        for(string c:commands){
            if(c=="UP"){
                pos.first -= 1;
            }
           else if(c=="DOWN"){
                pos.first += 1;
            }
           else if(c=="RIGHT"){
                pos.second += 1;
            }
            else{
                pos.second -= 1;
            }
        }

        return ((pos.first*n) + pos.second);
    }
};