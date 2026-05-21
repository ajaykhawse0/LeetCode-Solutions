class Solution {
public:
int firstDigit( int n) {
    while(n>=10){
        n/=10;
    }
    return n;
}
    int countBeautifulPairs(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int firstD = firstDigit(nums[i]);
            for(int j=i+1;j<nums.size();j++){
                int lastD = nums[j]%10;

                if(gcd(firstD,lastD)==1){
                    cnt++;
                }
            }
        }
    return cnt;}
};