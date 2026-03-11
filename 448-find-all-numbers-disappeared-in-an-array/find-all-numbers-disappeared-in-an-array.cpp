class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    //     unordered_set<int>st(nums.begin(),nums.end());
    
    //     vector<int>ans;
        int n = nums.size();
    //     for(int i=1;i<=n;i++){
    //         if(!st.count(i)){
    //             ans.push_back(i);
    //         }
    //     }
    //    return ans; 
        
       //marks all idx with values as -1

       for(int i=0;i<n;i++){
        int idx = abs(nums[i])-1;
        if(nums[idx]>0){
            nums[idx]=-nums[idx];
        }
        
       }
       vector<int>ans;
       for(int i=0;i<n;i++){
        if(nums[i]>0)ans.push_back(i+1);
       }
    return ans;}
};