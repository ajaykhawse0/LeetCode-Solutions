class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int score  = 0;

        while(true){
            if((a==0&&b==0) || (c==0&&b==0) || (a==0&&c==0))break;
            if(a>=b && a>=c){
                if(b>=c){
                    score ++;
                    a--;
                    b--;
                }
                else{
                    score++;
                    a--;
                    c--;
                }
            } 
           else if(b>=a && b>=c){
                if(a>=c){
                    score ++;
                    a--;
                    b--;
                }
                else{
                    score++;
                    b--;
                    c--;
                }
            } 
           else if(c>=a && c>=b){
                if(a>=b){
                    score ++;
                    a--;
                    c--;
                }
                else{
                    score++;
                    b--;
                    c--;
                }
            } 
        }
    return score;}
};