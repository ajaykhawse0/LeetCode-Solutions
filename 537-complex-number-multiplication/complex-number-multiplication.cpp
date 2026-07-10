class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int realA,realB,imgA,imgB;
        char extra;
        stringstream ss1(num1);
        stringstream ss2(num2);
        stringstream ans;

        ss1>>realA>>extra>>imgA>>extra;
        ss2>>realB>>extra>>imgB>>extra;
       
       int first = realA * realB - imgA * imgB;
       int second = realA * imgB + realB  * imgA;
       //adding it to ans
        ans<<first << '+'<<second<<'i';

        return ans.str();

    }
};