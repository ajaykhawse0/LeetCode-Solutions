class Solution {
public:
    bool canAliceWin(int n) {
        int rem = 10;
        int move = 0;

        while(true){
            if(move==0){
               if(n<rem)return false;
               n-=rem;
               move = 1-move;
            }
            else{
                if(n<rem)return true;
               n-=rem;
                 move = 1-move;
            }

            rem--;
        }
    return false;}
};