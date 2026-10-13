class Solution {
public:
   
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool>lockedRow(n,false);
        vector<bool>lockedCol(n,false);

  

        long long sum = 0;
        int m = queries.size();

        int rowsLeft = n;
        int colsLeft = n;
        
        for(int i=m-1;i>=0;i--){
             int type = queries[i][0];       
             int index = queries[i][1];       
             int val = queries[i][2];   

             if(type==0){
                if(lockedRow[index])continue;

                sum += 1LL*val*colsLeft;
                lockedRow[index] = true;

                rowsLeft--;
             }    
             else{
                if(lockedCol[index])continue;

                sum += 1LL*val*rowsLeft;
                 lockedCol[index] = true;
                colsLeft--;
             }    
        }


       
 return sum;   }
};