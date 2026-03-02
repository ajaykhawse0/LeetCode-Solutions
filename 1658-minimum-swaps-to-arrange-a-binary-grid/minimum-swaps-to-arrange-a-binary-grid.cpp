class Solution {
public:
int n ;
bool isSorted(vector<vector<int>>& grid){
    for(int i=0;i<n;i++){
        
         if(grid[i][i]!=1)return false;
    }
    return true;
}
    int minSwaps(vector<vector<int>>& grid) {
        n = grid.size();
        if(isSorted(grid))return 0;

        vector<int>trialingZeros(n);
        //In row 0 required Zeros are 2 at top of diagonal
        //In row 1 required Zeros are 1 at top of diagonal
        //In row 2 required Zeros are 0 at top of diagonal

        //count trailing zeros each row
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=n-1;j>=0;j--){
                 if(grid[i][j]==0){
                    count++;
                 }
                 else break;
            }

            trialingZeros[i]=count;


        }
           
        int swaps = 0;

        for(int i=0;i<n;i++){
            int reqZero = n-1-i;
            int j=i;

            while(j<n && trialingZeros[j]<reqZero){
                j++;
            }

            if(j==n)return -1;

            while(j>i){
                swap(trialingZeros[j],trialingZeros[j-1]);
                swaps++;
                j--;
            }


        }
  return swaps;  }
};