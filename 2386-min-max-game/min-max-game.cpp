class Solution {
public:
    int solve(vector<int>&arr){
        if(arr.size()==1)return arr[0];
        int n = arr.size();
        vector<int>newArr(n/2);

        for(int i=0;i<n/2;i++){
           if(i&1) newArr[i] = max(arr[2*i],arr[2*i+1]);
           else newArr[i] = min(arr[2*i],arr[2*i+1]);
        }

        return solve(newArr);
    }
    int minMaxGame(vector<int>& nums) {
        return solve(nums);
    }
};