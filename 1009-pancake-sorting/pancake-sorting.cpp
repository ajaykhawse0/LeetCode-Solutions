class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();

        for(int i = n - 1; i > 0; i--) {
            for(int j = 0; j <= i; j++) {
                if(arr[j] == i + 1) {
                 
                 if(j!=i){// bring max to front
                    reverse(arr.begin(), arr.begin() + j + 1);

                    // move max to correct position
                    reverse(arr.begin(), arr.begin() + i + 1);}

                    ans.push_back(j + 1);
                    ans.push_back(i + 1);

                    break;
                }
            }
        }
        return ans;
    }
};