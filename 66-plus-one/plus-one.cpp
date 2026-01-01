class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1;
        while(i>=0){
            if(digits[i]<9){
                digits[i]+=1;
                return digits;
            }

            if(digits[i]==9){
                digits[i]=0;
                i--;
            }
        }
        //if it reaches here it means digits are like 999 , 9999,99
        digits.insert(begin(digits),1);//it will become 1000,10000,100
        return digits;
    }
};