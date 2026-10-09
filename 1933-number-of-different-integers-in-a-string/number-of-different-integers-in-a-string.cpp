class Solution {
public:
    int numDifferentIntegers(string word) {
        bool allDigits=true;
        for(char c:word){
            if(!isdigit(c)){
                allDigits = false;
                break;
            }
        }
        if(allDigits)return 1;
        unordered_set<string>st;
        int i=0;
        while(i<word.size()){
            if(isdigit(word[i])){
                string temp = "";
                while(i<word.size()&&isdigit(word[i])){
                    temp += word[i];
                    i++;
                }
                int j=0;
                while(j<temp.size() && temp[j]=='0')j++;
               temp =  temp.substr(j);
               st.insert(temp);

            }
            else{
                i++;
            }
        }
  return st.size();  }
};