class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int,int>lastIdx,maxDiff;

        int n = nums.size();

        for(int i=0;i<n;i++){
            if(lastIdx.count(nums[i])){
                maxDiff[nums[i]]=max(maxDiff[nums[i]],i-lastIdx[nums[i]]-1);
            }
            lastIdx[nums[i]] = i;
        }

        for(int i=0;i<n;i++){
            //circular one
            maxDiff[nums[i]] = max(maxDiff[nums[i]],(i-lastIdx[nums[i]]-1 + n)%n);

            lastIdx[nums[i]] = i;

        }
        int ans = INT_MAX;

        for(auto&[key,val]:maxDiff){
            ans = min(ans,val);
        }

        return (ans+1)/2;
    }
};