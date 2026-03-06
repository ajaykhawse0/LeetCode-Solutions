class Solution {
public:
    void sortColors(vector<int>& nums) {
        //REv
        int zero=0;
        int one=0;
        int two = nums.size()-1;

        while(one<=two){
            if(nums[one]==0){
                swap(nums[one],nums[zero]);
                zero++;
                one++;
            }
            else if(nums[one]==2){
                 swap(nums[one],nums[two]);
                two--;
           

            }
            else{
                //nums[one]==1
                 one++;
            }
        }
    }
};