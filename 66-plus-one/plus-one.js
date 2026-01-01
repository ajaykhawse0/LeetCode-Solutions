/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    let n = digits.length;
    let i = n-1;
    while(i>=0){
     if(digits[i]<9){
                digits[i]+=1;
                return digits;
            }

            if(digits[i]==9){
                digits[i]=0;
                i--;
            }     }
   digits.unshift(1);
   return digits;
    
};