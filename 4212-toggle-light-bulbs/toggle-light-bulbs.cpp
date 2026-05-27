class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>bulb(101,0);

        for(int i=0;i<bulbs.size();i++){
            if(bulb[bulbs[i]]==1){
                bulb[bulbs[i]]=0;
            }
            else{
            bulb[bulbs[i]]=1;
        }
        }

        vector<int>ans;

        for(int i=1;i<=100;i++){
            if(bulb[i]==1){
                ans.push_back(i);
            }
        }
        
    return ans;}
};