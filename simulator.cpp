#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 10

time_t startTime;

void setupSensors() {
    printf("Sensors setup.\n");
    startTime = time(NULL);
}

void setBotSpeed(int speed) {
    printf("Bot speed set to %d.\n", speed);
}

unsigned int predefinedEchoTimes[ARRAY_SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
unsigned int predefinedEchoLatitude[ARRAY_SIZE] = {100, 90, 80, 90, 70, 80, 60, 70, 80, 100};
unsigned int predefinedEchoLongitude[ARRAY_SIZE] = {110, 120, 130, 140, 150, 160, 170, 180, 190, 200};

unsigned int readUltrasoundEchoTime() {
    time_t currentTime = time(NULL);
    double elapsedTime = difftime(currentTime, startTime);
    int index = (int)(elapsedTime / 3);
    return predefinedEchoTimes[index % ARRAY_SIZE];
}

unsigned long int readLatitude() {
    time_t currentTime = time(NULL);
    double elapsedTime = difftime(currentTime, startTime);
    int index = (int)(elapsedTime / 3);
    return predefinedEchoLatitude[index % ARRAY_SIZE];
}

unsigned long int readLongitude() {
    time_t currentTime = time(NULL);
    double elapsedTime = difftime(currentTime, startTime);
    int index = (int)(elapsedTime / 3);
    return predefinedEchoLongitude[index % ARRAY_SIZE];
}
