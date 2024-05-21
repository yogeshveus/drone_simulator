#include <stdio.h>
#include <time.h>
#include "data.cpp"

#define ARRAY_SIZE 10

time_t startTime;

void setupSensors() {
    printf("Sensors setup.\n");
    startTime = time(NULL);
}

void setBotSpeed(int speed) {
    printf("Bot speed set to %d.\n", speed);
}

const double *predefinedEchoTimes = y;
const double *predefinedEchoLatitude = x;

double readUltrasoundEchoTime() {
    time_t currentTime = time(NULL);
    double elapsedTime = difftime(currentTime, startTime);
    int index = (int)(elapsedTime / 3);
    return predefinedEchoTimes[index];
}

double readLatitude() {
    time_t currentTime = time(NULL);
    double elapsedTime = difftime(currentTime, startTime);
    int index = (int)(elapsedTime / 3);
    return predefinedEchoLatitude[index];
}

double readLongitude(){
    return 0;
}