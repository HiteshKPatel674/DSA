class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12)
            hour = 0;

        double angle = abs((11.0 * minutes) / 2 - 30.0 * hour);

        if(angle > 180)
            angle = 360 - angle;

        return angle;
    }
};