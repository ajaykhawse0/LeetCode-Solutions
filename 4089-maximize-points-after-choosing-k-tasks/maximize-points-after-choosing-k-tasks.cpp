class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        long long res = 0;
        
        priority_queue<int,vector<int>,greater<int>>diff;
        int n = technique1.size();
        for(int i=0;i<n;i++){
            res += max(technique1[i],technique2[i]);

            if(technique1[i]>=technique2[i]){
                k--;
            }
            else{
                diff.push(technique2[i]-technique1[i]);
            }
        }

        while(k>0 && !diff.empty()){
            res -= diff.top();
            k--;
            diff.pop();
        }
        // diff.clear();
    return res;}
};