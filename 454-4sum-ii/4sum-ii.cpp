class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //O(n^2) can only work
        int n = nums1.size();
        unordered_map<int,int>mpp;
        for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
               int a = nums1[i];
               int b = nums2[j];

               int sum = a+b;
               mpp[sum]++;
        }
        }

        int count=0;
        for(int k = 0 ; k < n ; k++ ){
        for(int l = 0 ; l < n ; l++ ){
               int c = nums3[k];
               int d = nums4[l];

               int target = -(c+d);

               if(mpp.find(target)!=mpp.end()){
                count+=mpp[target];
               }
               
        }
        }
        
    return count;}
};