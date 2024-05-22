#include "simulator.cpp"

void loop() {
    unsigned int echo_time = readUltrasoundEchoTime();
    unsigned long int lat = readLatitude();
    printf("%u %lu\n", echo_time, lat);
}

void setup() {
    setupSensors();
    setBotSpeed(40);
}