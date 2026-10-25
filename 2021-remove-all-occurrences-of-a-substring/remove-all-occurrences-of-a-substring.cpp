class Solution {
public:
    string removeOccurrences(string s, string part) {
        string temp;
        int n = s.size();
        int m = part.size();

        for(int i=0;i<n;i++){
            temp += s[i];

            if(temp.size()>=m && temp.back() == part.back()){
                int len = temp.size();
                string t = temp.substr(len-m);

                if(t==part){
                    for(int j = len-1;j>=len-m;j--){
                        temp.pop_back();
                    }
                }
            }
        }
 return temp;   }
};