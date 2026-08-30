class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        if (mn == mx)
            return 1;

        int n = nums.size();
        int ans = INT_MAX;

        // 1. Delete both min and max from the front
        bool foundMn = false;
        bool foundMx = false;
        int i = 0;

        while (i < n) {
            if (nums[i] == mn)
                foundMn = true;

            if (nums[i] == mx)
                foundMx = true;

            i++;

            if (foundMn && foundMx)
                break;
        }

        ans = min(ans, i);


        // 2. Delete both min and max from the back
        foundMn = false;
        foundMx = false;
        i = n - 1;

        while (i >= 0) {
            if (nums[i] == mn)
                foundMn = true;

            if (nums[i] == mx)
                foundMx = true;

            i--;

            if (foundMn && foundMx)
                break;
        }

        // Number of elements deleted = n - (remaining index + 1)
        ans = min(ans, n - 1 - i);


        // 3. Delete min from front and max from back
        foundMn = false;
        foundMx = false;

        i = 0;
        int j = n - 1;

        // Find min from front
        while (i < n) {
            if (nums[i] == mn) {
                foundMn = true;
                break;
            }
            i++;
        }

        // Find max from back
        while (j >= 0) {
            if (nums[j] == mx) {
                foundMx = true;
                break;
            }
            j--;
        }

        ans = min(ans, (i + 1) + (n - j));


        // 4. Delete max from front and min from back
        foundMn = false;
        foundMx = false;

        i = 0;
        j = n - 1;

        // Find max from front
        while (i < n) {
            if (nums[i] == mx) {
                foundMx = true;
                break;
            }
            i++;
        }

        // Find min from back
        while (j >= 0) {
            if (nums[j] == mn) {
                foundMn = true;
                break;
            }
            j--;
        }

        ans = min(ans, (i + 1) + (n - j));

        return ans;
    }
};