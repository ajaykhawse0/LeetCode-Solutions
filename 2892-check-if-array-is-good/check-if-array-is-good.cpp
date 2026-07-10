class Solution {
public:
    bool isGood(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        if(n!=mx+1)return false;
        unordered_set<int>st;
        int cnt = 0;
        for(int i=0;i<n;i++){
           if(nums[i]==mx)cnt++;
           st.insert(nums[i]);
        }
        for(int i=1;i<n;i++){
            if(!st.count(i))return false;
        }

        return cnt==2?true:false;
    }
};