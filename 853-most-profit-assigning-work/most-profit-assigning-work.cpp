class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(),worker.end());
        vector<pair<int,int>>diffXPro;
        int n=difficulty.size();
        for(int i=0;i<n;i++){
            diffXPro.push_back({difficulty[i],profit[i]});
        }
        sort(diffXPro.begin(),diffXPro.end());

        int j=0;
   
        int best =0;
        int ans =0;
        for(int ability : worker){
            
            while(j<n && ability >= diffXPro[j].first){
                best = max(best,diffXPro[j].second);
                j++;
            }
            ans+=best;
        }
return ans;
    }
};