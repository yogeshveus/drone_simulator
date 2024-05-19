#include "simulator.h"
#include <stdio.h>  // Not allowed in submissions

void setup(){
    setupSensors();
    setBotSpeed(100); // unit?
    // Reminder : Errors should arrise
}

void loop(){
    printf("EchoTime Latitude Longitude\n")
    while(echo_time > 0){
        unsigned int echo_time = readUltrasoundEchoTime();
        unsigned long int lat = readLattitude();
        unsigned long int lon = readLongitude();
        printf("%d %d %d\n", echo_time, lat, lon);
    }
}
    