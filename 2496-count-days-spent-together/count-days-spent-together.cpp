class Solution {
public:
    vector<int> monthDays = {0,   31,  59,  90,  120, 151,
                             181, 212, 243, 273, 304, 334};
    int toDays(string date) {
        int month = stoi(date.substr(0,2));
        int days  = stoi(date.substr(3));

        return monthDays[month-1]+days;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
            int start = max(toDays(arriveAlice),toDays(arriveBob));
            int end = min(toDays(leaveAlice),toDays(leaveBob));


            return max(0,end - start + 1);

                          }
};