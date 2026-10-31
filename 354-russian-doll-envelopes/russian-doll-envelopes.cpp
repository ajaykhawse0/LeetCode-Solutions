class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [&](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];

                 return a[0] < b[0];
             });

             vector<int>tails;

             for(auto e:envelopes){
                int height = e[1];
                //because we already sorted by width

                auto it = lower_bound(tails.begin(), tails.end(),height);
                
                if(it==tails.end()){//height is not there
                    tails.push_back(height);
                }
                else{
                    *it = height;
                }

             }
 return tails.size();   }
};