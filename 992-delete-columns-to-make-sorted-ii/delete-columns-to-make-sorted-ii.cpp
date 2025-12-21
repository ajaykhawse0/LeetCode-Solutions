class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        //to find the deletions we will move col wise from left to right
        // if there is violation the deletion will be increased

        int n = strs.size();
         int col = strs[0].size();
          
        int deletions = 0;

         vector<bool>resolved(n-1,0);
         int unresolved = n-1;

         for(int c=0;c<col && unresolved>=0;c++){
             bool bad = false;           

            for(int i=0;i<n-1;i++){
                if(!resolved[i] && strs[i][c]> strs[i+1][c]){
                    bad = true;
                    break;

                }}

                if(bad){
                    deletions++;
                    continue;
                }
            
            for(int i=0;i<n-1;i++){
               if(!resolved[i] && strs[i][c] < strs[i+1][c]){
                resolved[i] = true;
                unresolved--;
               }
            }
         }
 return deletions;   }
};