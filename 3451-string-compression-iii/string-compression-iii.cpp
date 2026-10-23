class Solution {
public:
    string compressedString(string word) {
        string comp="";

        int n = word.size();
        
        for(int i=0;i<n;){
            char c = word[i];
            int count = 0;

            while(i<n && c==word[i] && count<9){
                i++;
                count++;
            }

            comp += (count+'0');
            comp += c;
        }
 return comp;   }
};