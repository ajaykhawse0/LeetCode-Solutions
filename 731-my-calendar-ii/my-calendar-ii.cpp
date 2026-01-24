class MyCalendarTwo {
public:
    map<int, int> events;
    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {
        // check
        events[startTime]++;
        events[endTime]--;

        int active = 0;

        for (auto& event : events) {
            active+=event.second;

            if(active>=3){

                 events[startTime]--;//remove event;
                 if(events[startTime]==0){
                    events.erase(startTime);
                 }

                 events[endTime]++;//remove event;
                 if(events[endTime]==0){
                    events.erase(endTime);
                 }
                 return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */