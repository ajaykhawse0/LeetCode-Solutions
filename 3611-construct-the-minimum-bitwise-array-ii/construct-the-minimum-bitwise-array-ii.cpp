class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int N = nums.size();
        vector<int>ans(N,-1);
        for(int i=0;i<N;i++){
            if(nums[i]==2){
                continue;//ans[i]=-1;
            }
              
             int n = nums[i] ;
             int pos = 0;//right to left scan will start from right most bit (LSB)which is at 0 th position
            //firstly we will scan and count 1'sfrom left to bit bitwise till first zero is found

            while(n>0 && ((n >> pos) & 1)==1){
                // ((n >> pos)&1==1) this statement eifht here firstly shifts n in right till the pos index and then compare that the bit at the pos is already set or not if yes increase pos pointer;

                pos++;
            }

            // now after scanning all the bits two cases can appear in front of us

            //1. All bits are set like for 7 = 111(in binary)
            if((1 << pos) > n){
                // (1 << pos) > n this checks the given n has all set bits or not if yes then shift 1's all bits to left till pos will result in aa greater number than given n 
                
                /*demonstration for binary representation is (111) then pos will start from
                pos=0 after gettting setted bit it increases to 1
                At pos=1 after gettting setted bit it increases to 2
                At pos=2 after gettting setted bit it increases to 3

                and (1<<3) = 8 which is greater than 7 
                */

                //Now find the position of first setted bit in binary

                int highestBit = 31 - __builtin_clz(n);
                //__builtin_clz(x) is a GCC and Clang compiler intrinsic function that counts the number of leading zero bits in a given unsigned integer x

                
                // then compute the value of n
                // by doing AND operation with the compliment of (1<<highestBit)
                //in case of 7 highest bit will be 31 - 29 = 2 
                // so 1<<2 = 0000..000,100
                //its compliment will be 1111...111,011
                //so n = 7 & (3) = 111 & 011 = 011 = 3
                n = n & ~(1<<highestBit); 
            }

       //second posibility is no like 11 (1011)in binary it has a zero in in its representation
       //So for 11 pos will be like pos = 3 
       // then what we will do  we will left shift 1 till pos-1 then takes its compliment 
       //and so (AND) operation with n
       /*
       Demonstration
       11 = 1011 , pos = 2
       (1<<(pos-1)) = 1<<1 = 00...10
       compliment = 11...101
       n = 00...1011 & 11...101 = 00....1001 = 9 
       */
       else{
        n = n & ~(1<<(pos-1));
       }

            
    ans[i]=n;    }
   return ans; }
};