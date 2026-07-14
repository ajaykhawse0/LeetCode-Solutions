class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int cnt = 0;
        int m = flowerbed.size();

        for (int i = 0; i < m; i++) {

            bool left = (i == 0 || flowerbed[i - 1] == 0);
            bool right = (i == m - 1 || flowerbed[i + 1] == 0);

            if (flowerbed[i] == 0 && left && right) {
                flowerbed[i] = 1;
                cnt++;

                if (cnt >= n)
                    return true;
            }
        }

        return cnt >= n;
    }
};