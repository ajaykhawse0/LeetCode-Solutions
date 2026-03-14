class Solution {
public:
    string getHappyString(int n, int k) {
          //Brute Force;
           string curr ="";
        string res = "";
        vector<string>str;

        generateString(curr,n,str);

        if(str.size()<k)return "";

        return str[k-1];

        
    }
    void generateString(string& curr,int n,vector<string>&str){
        if(curr.size()==n){
           str.push_back(curr);
            return;
        }
        
        for(char ch = 'a';ch<='c';ch++){
            if(curr.size()>0 && curr.back()==ch)continue;
            curr = curr+ch;
            generateString(curr,n,str);

            curr.pop_back();//backtrack
             
        }


    }
};