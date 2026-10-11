class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2==1)return {};
        sort(changed.begin(),changed.end());
        map<int,int>mpp;
        vector<int>ans;

        for(int c:changed){
            mpp[c]++;
        }
        for(int c:changed){
            if(mpp[c]==0)continue;
            if(mpp[2*c]==0)return{};

            ans.push_back(c);
            mpp[c]--;
            mpp[2*c]--;
        }


        return ans;
    }
};