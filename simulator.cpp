#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "data.cpp"

time_t startTime;
bool flag = false;
float botSpeed;

void setupSensors() {
    // printf("Sensors setup.\n");
    startTime = time(NULL);
    flag = true;
}

void setBotSpeed(float speed) {
    if (!flag) {
        printf("Error: Sensors not set up. Call setupSensors() first.\n");
        return;
    }
    // printf("Bot speed set to %d.\n", speed);
    botSpeed = speed;
}

const double *predefinedEchoTimes = y;
const double *predefinedEchoLatitude = x;

int calculateIndex(){
    if (!flag) {
        printf("Error: Sensors not set up. Call setupSensors() first.\n");
        return 0;
    }
    time_t currentTime = time(NULL);
    double elapsedTime = difftime(currentTime, startTime);
    int index = (int)(elapsedTime * botSpeed / distance_step);    
    if(index>=num_points)
    {
        index=num_points-1;
    }
    return index;
}

double readUltrasoundEchoTime() {
    return predefinedEchoTimes[calculateIndex()];
}

double readLatitude() {
    return predefinedEchoLatitude[calculateIndex()];
}
