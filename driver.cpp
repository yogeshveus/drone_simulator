#include "drone.ino"

int main(){
    setup();
    while(true){
        loop();
        if(readLatitude() >= 3000){
            printf("Number of buildings detected: %d\n", NUMBER_OF_BUILDINGS);
            break;
        }
    }
}