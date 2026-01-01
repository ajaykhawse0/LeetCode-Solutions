class Solution {
public:
int totalRows,totalCols;
vector<vector<int>>dirs={{-1,0},{0,1},{1,0},{0,-1}};
     bool canStillCross(int day,vector<vector<int>>& cells){
        vector<vector<int>>grid(totalRows,vector<int>(totalCols,0));
        for(int i=0;i<day;i++){
            int r = cells[i][0]-1;
            int c = cells[i][1]-1;
            grid[r][c]=1;

        }
        //bfs
        queue<pair<int,int>>bfsQueue;
        vector<vector<bool>>visited(totalRows,vector<bool>(totalCols,false));

        //iterate 1st row;
        for(int col =0;col<totalCols;col++){
            if(grid[0][col]==0){
                visited[0][col]=true;
                bfsQueue.push({0,col});
            }
        }
        
        while(!bfsQueue.empty()){
            pair<int,int>q=bfsQueue.front();
            bfsQueue.pop();
            int currRow = q.first;
            int currCol = q.second;
            if(currRow == totalRows-1)return true;

            for(auto &d:dirs){
                int newRow=currRow+d[0];
                int newCol=currCol+d[1];

                if(newRow >= 0 && newRow < totalRows && newCol >= 0 && newCol < totalCols && !visited[newRow][newCol] && grid[newRow][newCol] == 0){
                     visited[newRow][newCol]=true;
                bfsQueue.push({newRow,newCol});
                }
            }
        }


    return false; }


    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        totalRows=row;
        totalCols=col;

        int answer=1;

        int left = 1;
        int right = cells.size();

        while(left<=right){
            int mid = left+(right-left)/2;
            if(canStillCross(mid,cells)){
                answer=mid;
                left = mid+1;

            }
            else{
            right=mid-1;}
        }
 return answer;   }
};