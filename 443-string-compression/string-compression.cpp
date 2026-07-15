class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int j = 0;
        int count = 0;
        char letter='\0';

        while(i<n){
            letter = chars[i];
            count = 1;
            i++;
            while(i<n && chars[i]==letter){
                count++;
                i++; 
            }
            chars[j++] = letter;

            if(count>1){
                for(char c:to_string(count)){
                    chars[j++] = c;
                }
            }
        }
        chars.resize(j);
 return j ;  }
};