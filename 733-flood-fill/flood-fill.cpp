class Solution {
   
     vector<vector<int>>dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(int sr,int sc,int m,int n,vector<vector<int>>&image,vector<vector<int>>&vis,int color,int originalColor){
          
          vis[sr][sc] = 1;
          image[sr][sc] = color;

          for(int i=0;i<4;i++){
            int nrow = dirs[i][0] + sr;
            int ncol = dirs[i][1] + sc;

            if(nrow >= 0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && image[nrow][ncol] == originalColor ){
                dfs(nrow,ncol,m,n,image,vis,color,originalColor);
            }
                      }


    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        if(image[sr][sc]==color)return image;
        int originalcolor =  image[sr][sc];
        
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));

        dfs(sr,sc,m,n,image,vis,color,originalcolor);
        return image;
    }
};