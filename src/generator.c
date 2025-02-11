#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "traffic_simulation.h"

void writeVehicleToFile(FILE *file, Vehicle *vehicle) {
    fprintf(file, "%f %f %d %d %d %d %d\n", 
            vehicle->x, vehicle->y, 
            vehicle->direction, 
            vehicle->type, 
            vehicle->turnDirection, 
            vehicle->state, 
            vehicle->speed);
}

int SDL_main(int argc, char *argv[]) {
    srand(time(NULL));
    FILE *file = fopen("bin/vehicles.txt", "w");
    if (!file) {
        perror("Failed to open vehicles.txt");
        return 1;
    }

    while (1) {
        // Generation of a new vehicle
        Direction spawnDirection = (Direction)(rand() % 4);
        Vehicle *newVehicle = createVehicle(spawnDirection);


        // Write the vehicle data to the file
        writeVehicleToFile(file, newVehicle);
        fflush(file); // Ensure data is written to the file immediately

        // Free the vehicle memory
        free(newVehicle);

        // Wait for a short period before generating the next vehicle
        SDL_Delay(2000); // 2 seconds delay
    }
//vehicle gen delay added
    fclose(file);
    return 0;
}
//Use queue operations to enqueue vehicles into their respective lanes
// Additional comments for future expansion
// TODO: Implement priority-based queueing for emergency vehicles
// TODO: Optimize file I/O operations to reduce latency
// Placeholder for future debugging logs
// Code formatting check