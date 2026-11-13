class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        //sliding window 
        //monotic increasing deque
        
        int n = nums.size();

        int right = n-1;

        long long ans = 0;
        long long cost = 0;
        deque<pair<int,int>>dq;//{value,operations}

        for(int left = n-1;left>=0;left--){
            int cnt = 1;
            while(!dq.empty() && dq.back().first<nums[left]){
                cost += 1LL*(nums[left]-dq.back().first)*dq.back().second;//cost to make it eqaul to new element nums[left];

                cnt += dq.back().second;//curr cnt of ele
                dq.pop_back();
            }

            dq.push_back({nums[left],cnt});

            while(cost>k){
                cost -= 1LL*(dq.front().first-nums[right]);

                if(dq.front().second==1)dq.pop_front();
                else dq.front().second--;

                right--;
            }

            ans += (right-left+1);
        }
        
           return ans; }
};