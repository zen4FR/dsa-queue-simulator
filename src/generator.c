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

    printf("Vehicle generation started...\n"); // Debug print statement (1st extra line)

    while (1) {
        // Generation of a new vehicle
        Direction spawnDirection = (Direction)(rand() % 4);
        Vehicle *newVehicle = createVehicle(spawnDirection);

        printf("Generated vehicle at direction: %d\n", spawnDirection); // Debug print (2nd extra line)

        // Write the vehicle data to the file
        writeVehicleToFile(file, newVehicle);
        fflush(file); // Ensure data is written to the file immediately

        // Free the vehicle memory
        free(newVehicle);

        // Wait for a short period before generating the next vehicle
        SDL_Delay(1000); // 2 seconds delay
    }

    //vehicle gen delay added
    printf("Vehicle generation loop ended.\n"); // Debug print (3rd extra line)
    
    fclose(file);
    printf("File closed successfully.\n"); // Debug print (4th extra line)
    
    return 0;
}
