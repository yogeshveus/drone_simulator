#include "../simulator.cpp"
#include <stdio.h> // Not allowed in submissions


#define DRONE_SPEED 40

void loop() {
    printf("EchoTime Latitude Longitude\n");
    while (1) {
        unsigned int echo_time = readUltrasoundEchoTime();
        if (echo_time == 0) break;
        unsigned long int lat = readLatitude();
        // unsigned long int lon = readLongitude();
        // printf("%u %lu %lu\n", echo_time, lat, lon);
        printf("%u %lu\n", echo_time, lat);
        // sleep(2);
    }
}

void setup() {
    setupSensors();
    setBotSpeed(DRONE_SPEED); // unit?
    printf("Setup completed.\n");
    // Reminder : Errors should arrise
}

int main() {
    setup();
    // sleep(5);
    loop();
    return 0;
}
