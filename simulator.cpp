#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "data.cpp"

#define ARRAY_SIZE 10

time_t startTime;
bool flag = false;

void setupSensors() {
    printf("Sensors setup.\n");
    startTime = time(NULL);
    flag = true;
}

void setBotSpeed(int speed) {
    if (!flag) {
        printf("Error: Sensors not set up. Call setupSensors() first.\n");
        return;
    }
    printf("Bot speed set to %d.\n", speed);
}

const double *predefinedEchoTimes = y;
const double *predefinedEchoLatitude = x;

double readUltrasoundEchoTime() {
    if (!flag) {
        printf("Error: Sensors not set up. Call setupSensors() first.\n");
        return 0;
    }
    time_t currentTime = time(NULL);
    double elapsedTime = difftime(currentTime, startTime);
    int index = (int)(elapsedTime / 3);
    
    if(index>=num_points)
    {
        index=num_points-1;
    }
    return predefinedEchoTimes[index];
}

double readLatitude() {
    if (!flag) {
        printf("Error: Sensors not set up. Call setupSensors() first.\n");
        return 0;
    }
    time_t currentTime = time(NULL);
    double elapsedTime = difftime(currentTime, startTime);
    int index = (int)(elapsedTime / 3);
   
    if(index>=num_points)
    {
        index=num_points-1;
    }
    return predefinedEchoLatitude[index];
}

double readLongitude(){
    if (!flag) {
        printf("Error: Sensors not set up. Call setupSensors() first.\n");
        return 0;
    }
    return 0;
}
