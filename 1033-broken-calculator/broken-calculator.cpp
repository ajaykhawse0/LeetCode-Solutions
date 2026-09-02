class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans  = 0;
        //backward greedy
        while(startValue<target){
            if(target%2==0){
                target /= 2;
            }
            else{
                target++;
            }
            ans++;
        }
        ans += startValue-target;
    return ans;}
};