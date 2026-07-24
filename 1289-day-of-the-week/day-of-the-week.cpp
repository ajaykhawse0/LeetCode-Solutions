class Solution {
public:
    bool isLeap(int y){
        if(y%400==0)return true;

        return (y%4==0 && y%100!=0);
    }
    string dayOfTheWeek(int day, int month, int year) {
        
        //1 jan 1971 was friday

        string week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        int daysInMonth[12] = {
            31,28,31,30,31,30,31,31,30,31,30,31
        };

        int totalDays = 0;

        for(int y=1971;y<year;y++){
            totalDays += isLeap(y)?366:365;
        }
        for(int m=1;m<month;m++){
            totalDays += daysInMonth[m-1];

            if(m==2 &&  isLeap(year))totalDays++;
        }
        
        totalDays += day-1;

        string ans = week[(5+totalDays)%7];

        return ans;

    }
};