// 4. Median of Two Sorted Arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
 vector<int> nums3(nums1.size() + nums2.size());
         merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums3.begin());

sort(nums3.begin(),nums3.end());

int n= nums3.size();

 if (n % 2 == 0) {
        
        return (nums3[n / 2 - 1] + nums3[n / 2]) / 2.0;
    } 

      else{ 
        return nums3[n / 2];
      }
   

        }
    //T.C. => O(m log(m+n))
    //S.C. => O(m+n)
};
