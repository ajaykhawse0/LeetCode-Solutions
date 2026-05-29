class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        int length = a+b+c;
        int i=0;
        int currA=0,currB=0,currC=0;

        while(i<length){

            if((currA!=2  && a >= b && a >= c) || (a>0 &&(currB==2 || currC==2))){
                ans += 'a';
                a--;
                currB=0;
                currC=0;
                currA++;
            }
            else if((currB!=2  && b >= a && b >= c) || (b>0 &&(currA==2 || currC==2))){
                ans += 'b';

                b--;
                currA=0;
                currC=0;
                currB++;
            }
            else if((currC!=2  && c >= b && c >= a) || (c>0 &&(currA==2 || currB==2))){
                ans += 'c';
                c--;
                currA=0;
                currB=0;
                currC++;
            }
            i++;
        }


          
return ans;
        
    }
};