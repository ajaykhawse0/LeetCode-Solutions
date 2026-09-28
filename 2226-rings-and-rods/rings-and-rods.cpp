class Solution {
public:
    int countPoints(string rings) {
        vector<bool>red(10,false);
        vector<bool>green(10,false);
        vector<bool>blue(10,false);

        for(int i=1;i<rings.size();i+=2){
           if(rings[i-1]=='R'){
            red[rings[i]-'0'] = true;
           }
           else if(rings[i-1]=='G'){
            green[rings[i]-'0'] = true;
           }
           else if(rings[i-1]=='B'){
            blue[rings[i]-'0'] = true;
           }
        }
        int ans = 0;
        for(int i=0;i<=9;i++){
            if(red[i] && green[i] && blue[i])ans++;
        }
return ans;    }
};