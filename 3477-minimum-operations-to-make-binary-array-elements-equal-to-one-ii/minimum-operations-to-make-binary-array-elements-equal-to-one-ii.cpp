class Solution {
public:
    int minOperations(vector<int>& nums) {
        // 01101
        // 10010=>1
        // 11101=>2
        // 11110=>3
        // 11111=>4

        // 1000
        // 1111=>1

        //change operations occurs only when the currentbit is different from previous bit
        //01101
        //in this ex 1st is 0 => op =1
        //second is 1 => op = 1
        //third is 1 which is sim,ilar to previous so = op =2
        // fourth bit is 0 d/f => op=3
        // fifth bit is 1 d/f = op = 
        // ans = 4
        
        int n = nums.size();
        int currBit = 0;
        int operations = 0;

        for(int i=0;i<n;i++){
            if(currBit == nums[i]){
                operations++;
                currBit = (currBit==0?1:0);
            }
        }


return operations;
    }
};