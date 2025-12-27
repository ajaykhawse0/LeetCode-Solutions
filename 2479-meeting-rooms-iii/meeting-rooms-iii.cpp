class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>busyRooms;//[end,room]
        priority_queue<int,vector<int>,greater<int>>freeRooms;
        for(int i=0;i<n;i++){

            freeRooms.push(i);
        }
        vector<int>countRooms(n,0);

         for( auto &meeting:meetings){
            int start=meeting[0],end=meeting[1];

            // if the meeeting that are being held in rooms are completed and pop that meetings and make the room vacant for other meets
            while(!busyRooms.empty() && busyRooms.top().first<=start){
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if(!freeRooms.empty()){
             int room = freeRooms.top();
             freeRooms.pop();
             busyRooms.push({end,room}); 
             countRooms[room]++;  
            }
            else{
                   // Delay meeting until earliest room is free
                auto[availTime,room]=busyRooms.top();
                busyRooms.pop();
                // push the current meeting with its duration+time required for current meeting to complete
                
                int duration =end-start;
                busyRooms.push({availTime+duration,room});
                countRooms[room]++;
            }
         }    

     // Find room with maximum meetings (tie → smallest number)
        int maxCount = 0;
        int resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (countRooms[i] > maxCount) {
                maxCount = countRooms[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
    
};