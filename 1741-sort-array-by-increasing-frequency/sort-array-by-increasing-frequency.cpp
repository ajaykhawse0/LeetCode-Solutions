class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>freq(201,0);

        for(int & num:nums){
            freq[num+100]++;
        }

        sort(nums.begin(),nums.end(),[&](int n1,int n2){
            if(freq[n1+100]!=freq[n2+100]){
                return freq[n1+100] < freq[n2+100];
            }
            return n1>n2;
        });

        return nums;
           
    }
};