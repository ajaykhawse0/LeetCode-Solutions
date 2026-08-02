class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        //prefix sum
        int n =tasks.size();
        vector<long long>pref(n+1,0);

        for(int i=0;i<n;i++){
            pref[i+1] = pref[i] + tasks[i];
        }

        long long done = 0;
        long long total = pref[n];
        vector<int>ans;

        for(long long shift : shifts){
            if(done+shift >= total){
                done = 0;
                ans.push_back(0);//all tasks completed 0  remaining
                continue;
            }

            done  += shift;

            //binary search
            int completed = upper_bound(pref.begin(),pref.end(),done) - pref.begin() - 1;
            ans.push_back(n-completed);
        } 
    return ans;}
};