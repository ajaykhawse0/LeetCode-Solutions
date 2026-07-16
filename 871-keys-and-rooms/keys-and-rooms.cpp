class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>vis(rooms.size(),false);
        vis[0] = true;

        queue<int>q;
        q.push(0);

        while(!q.empty()){
            int currRoom = q.front();
            q.pop();
            vis[currRoom] = true;

            for(int key:rooms[currRoom]){
                if(!vis[key]){
                    q.push(key);
                }
            }
        }
        for(auto&v:vis){
            if(!v)return false;
        }
           return true; }
};