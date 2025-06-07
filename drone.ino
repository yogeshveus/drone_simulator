#include "simulator.cpp"
#include <cmath>
#include <iostream>
using namespace std;
// void setupSensors()
// void setBotSpeed(float speed) m/s
// Total distance = 3km
// Maximum height reached by the drone = 1km
// double readUltrasoundEchoTime() - blocking function
// double readLatitude() - instantaneous function
// int NUMBER_OF_BUILDINGS
float distance(double t){
    float d = (t*1540)/2;
    return d;
}
float slope(double x, double xp, double y, double yp){
    double s;
    if(y-yp != 0){
        s = (x-xp)/(y-yp);
    }
    else{
        s = 0;
    }
    return s;
}
static int prevy;
static int prevx;
void loop() {
    bool inbuilding = false;
    double xx = readLatitude();
    double time = readUltrasoundEchoTime();
    double dis = distance(time);
    double change;
    /*if (prevy >= 0){
        double change = prevy - dis;
        if (change > 1){
            if(!inbuilding){
                NUMBER_OF_BUILDINGS++;
                inbuilding = true;
                printf("%lf\n", slope(xx, prevx, dis, prevy));
            }
            else{
                inbuilding = false;
                printf("%lf\n", slope(xx, prevx, dis, prevy));
            }
        }
    }
    prevy = dis;
    prevx = xx;*/
    double ss = slope(xx, prevx, dis, prevy);
    if (ss>0){
        change = prevy - dis;
        if (change > 0){
            if(!inbuilding){
                inbuilding  = true;
                NUMBER_OF_BUILDINGS++;
            }
            else{
                inbuilding = false;
            }
        }
        else if (change < -2){
            if(inbuilding){
                inbuilding = false;
            }
            else{
                inbuilding = true;
                NUMBER_OF_BUILDINGS++;
            }
        prevx = xx;
        prevy = dis;
    }
    else if (ss<0){
        change = prevy - dis;
        if (change > 0){
            if(!inbuilding){
                inbuilding = true;
                NUMBER_OF_BUILDINGS++;
            }
        }
        else if (change < 0){
            if(inbuilding){
                inbuilding = false;
            }
        }
        prevy = dis;
        prevx = xx;
    }
    else{
        change = prevy - dis;
        if(change > 0){
            inbuilding = true;
            NUMBER_OF_BUILDINGS++;
        }
        else if (change < 0){
            inbuilding = false;
        }
        prevx = xx;
        prevy = dis;
    }
    }
}

void setup() {
    setupSensors();
    setBotSpeed(20);
    prevx = -1;
    prevy = -1;
}