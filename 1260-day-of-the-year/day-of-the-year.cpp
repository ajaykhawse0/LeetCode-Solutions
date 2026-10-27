class Solution {
public:
    bool leapYear(int year){

        return (year%4==0)?((year%100==0)?((year%400==0)?true:false):true):false;
    }
    vector<int>days={31,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear(string date) {
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        int d = 0;
        if(month >2 && leapYear(year) ){
         d++;
        }
        while(--month>0){
            d += days[month-1];
        }

        d += day;


    return d;}
};