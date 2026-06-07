class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ///We will use recurssion + backtracking with take and skip approach
        vector<vector<int>>allCombos;
        int n = candidates.size();
        vector<int>combo;
        generatingFun(0,0,target,n,combo,candidates,allCombos);
        return allCombos;
    }
    void generatingFun(int i,int total,int target,int n , vector<int>&combo,vector<int>&candidates,vector<vector<int>>&allCombos){
        if(total==target){
            allCombos.push_back(combo);
            return;
        }
        if(i>=n || total>target)return;

        //take the current Element;
        combo.push_back(candidates[i]);
        generatingFun(i,total+candidates[i],target,n,combo,candidates,allCombos);

        //skip the current element
        combo.pop_back();
        generatingFun(i+1,total,target,n,combo,candidates,allCombos);
    }
};