class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size();
        int i=1;
        int j=0;
        vector<string>ans;
         
         while(i<=n && j < m){
            if(target[j]==i){
                ans.push_back("Push");
                j++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            i++;
         }
        
    return ans;}
};