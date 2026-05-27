class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n,0);
        queue<int>q;
        q.push(0);


        while(!q.empty()){
            int room = q.front();
            q.pop();

            visited[room]=1;

            for(int i:rooms[room]){
                if(!visited[i]){
                    q.push(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i])return false;
        }
    return true;}
};