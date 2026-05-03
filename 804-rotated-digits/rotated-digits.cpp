class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for(int i=1;i<=n;i++){
            int curr = i;
            bool valid = true;
            bool hasChanged = false;

            while(curr>0 && valid){
                int digit = curr%10;

                if(digit==3||digit==4||digit==7){
                    valid=false;
                    break;}
                    
                   else if(digit==2||digit==5||digit==6||digit==9){
                    hasChanged=true;
                   }
                   curr/=10;
            }
            if(valid && hasChanged)count++;
        }
    return count;}
};