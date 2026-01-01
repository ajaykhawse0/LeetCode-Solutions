class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        int i = n-1;
        while(i>=0){
            if(digits[i]<9){
                digits[i]+=1;
                return digits;

            }
            if(digits[i]==9){
                digits[i] = 0;
                i--;
            }
  
         }
      int[] newDigits = new int[n + 1];
        newDigits[0] = 1;  
return newDigits;    }
}