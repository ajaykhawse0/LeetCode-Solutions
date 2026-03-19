class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int hMax = longestSequence(hBars);
        int vMax = longestSequence(vBars);

        int side = min(hMax,vMax)+1;//+1 because  n bars make n+1 squares

        return side * side;
    }

    int longestSequence(vector<int>&arr){
        int maxLen = 1;
        int currLen = 1;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]-1){
                currLen++;
            }
            else{
                maxLen = max(maxLen,currLen);
                currLen=1;
            }
        }
         maxLen = max(maxLen,currLen);
    return maxLen;}
};