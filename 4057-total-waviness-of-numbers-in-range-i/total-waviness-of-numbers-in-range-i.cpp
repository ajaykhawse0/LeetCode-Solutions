class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int waviness=0; 
        while(num1<=num2){
            string s = to_string(num1);
            num1++;
            if(s.length()<3)continue;
            for(int i=1;i<s.length()-1;i++){
                if(s[i-1]<s[i] && s[i]>s[i+1] ){
                    waviness++;
      
                }
               else if(s[i-1]>s[i] && s[i]<s[i+1] ){
                    waviness++;

                }
            }
        }
 return waviness;   }
};