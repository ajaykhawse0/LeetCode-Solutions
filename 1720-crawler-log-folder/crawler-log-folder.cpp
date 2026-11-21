class Solution {
public:
    int minOperations(vector<string>& logs) {
        int folders = 0;

        for(string log:logs){
            if(log=="./")continue;
            if(log=="../"){
                if(folders)folders--;
            }
            else{
                folders++;
            }
        }
 return folders;   }
};