class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        

        if(st.size()<3)return *max_element(nums.begin(),nums.end());
        int maxFirst = INT_MIN;
        int maxSecond = INT_MIN;
        int maxThird = INT_MIN;

        for(int x:st){
            if(x>maxFirst){
                maxThird = maxSecond;
                maxSecond = maxFirst;
                maxFirst  = x;
            }
            else if(x>maxSecond){
                maxThird = maxSecond;
                
                maxSecond  = x;
            }
            else if(x>maxThird){
                maxThird = x;
            }
        }
    return maxThird;}
};