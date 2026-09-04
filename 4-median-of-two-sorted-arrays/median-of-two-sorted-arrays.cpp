class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        bool odd = ((m + n) & 1);
        int middle = (m + n) / 2;

        int l = 0;
        int r = 0;

        double ans = 0.0;

        if (odd) {

            while (l < n && r < m) {

                if (nums1[l] <= nums2[r]) {
                    l++;

                    if (l + r - 1 == middle)
                        return nums1[l - 1];
                }
                else {
                    r++;

                    if (l + r - 1 == middle)
                        return nums2[r - 1];
                }
            }

            while (l < n) {
                l++;

                if (l + r - 1 == middle)
                    return nums1[l - 1];
            }

            while (r < m) {
                r++;

                if (l + r - 1 == middle)
                    return nums2[r - 1];
            }
        }

        else {
            int prev = 0;
            int curr = 0;

            while (l < n && r < m) {

                if (nums1[l] <= nums2[r]) {
                    prev = curr;
                    curr = nums1[l];
                    l++;
                }
                else {
                    prev = curr;
                    curr = nums2[r];
                    r++;
                }

                if (l + r - 1 == middle) {
                    return (prev + curr) / 2.0;
                }
            }

            while (l < n) {

                prev = curr;
                curr = nums1[l];
                l++;

                if (l + r - 1 == middle) {
                    return (prev + curr) / 2.0;
                }
            }

            while (r < m) {

                prev = curr;
                curr = nums2[r];
                r++;

                if (l + r - 1 == middle) {
                    return (prev + curr) / 2.0;
                }
            }
        }

        return ans;
    }
};