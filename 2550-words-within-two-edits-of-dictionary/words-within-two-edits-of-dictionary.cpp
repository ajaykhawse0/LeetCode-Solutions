class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        int n = dictionary.size();
        for(auto&q:queries){
            string word = q;
            int wSize = word.size();
            for(int i=0;i<n;i++){
                int cnt=0;
                int dSize = dictionary[i].size();

                int w = 0,d=0;
                while(w<wSize && d<dSize){
                    if(word[w]!=dictionary[i][d]){
                        cnt++;
                    }
                    if(cnt>2)break;
                    w++;d++;

                }
                if(cnt<=2){
                    ans.push_back(q);
                    break;
                }
            }
        }
    return ans;}
};