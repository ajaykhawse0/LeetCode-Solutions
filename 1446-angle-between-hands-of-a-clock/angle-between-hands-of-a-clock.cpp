class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hAngle = 0;
        if(hour==12){
            hAngle=0;
        }
        else{
            hAngle = hour*30; 
        }
        double mAngle = minutes*6;
        //changes in hAngle ;
        hAngle += minutes*0.5;
      
        double difference = abs(hAngle-mAngle);
        double ans =  min(difference,360-difference);
        return ans;
    }
};