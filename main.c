#include <stdio.h>

// Function declarations
void initializeSystem(int lights[], int temp[], int motion[], int locks[], int rooms);
void toggleLight(int lights[], int rooms);
void readTemperature(int temp[], int rooms);
void checkMotion(int motion[], int rooms);
void lockUnlockSecurity(int locks[], int rooms);
void houseStatus(int lights[], int temp[], int motion[], int locks[], int rooms);

int main() {
    int rooms;
    printf("Enter number of rooms: ");
    scanf("%d", &rooms);

    // Arrays representing the system
    int lights[rooms], temp[rooms], motion[rooms], locks[rooms];
    
    // Initialize the system
    initializeSystem(lights, temp, motion, locks, rooms);
    
    int choice;
    do {
        printf("\n===== Smart Home Menu =====\n");
        printf("1. Toggle Light\n");
        printf("2. Read Temperature\n");
        printf("3. Check Motion Sensor\n");
        printf("4. Lock/Unlock Security System\n");
        printf("5. House Status Summary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: toggleLight(lights, rooms); break;
            case 2: readTemperature(temp, rooms); break;
            case 3: checkMotion(motion, rooms); break;
            case 4: lockUnlockSecurity(locks, rooms); break;
            case 5: houseStatus(lights, temp, motion, locks, rooms); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}

void initializeSystem(int lights[], int temp[], int motion[], int locks[], int rooms) {
    printf("Initializing system...\n");
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;      // All lights OFF
        temp[i] = 22 + (i % 5);  // Assigning some default temperatures
        motion[i] = 0;      // No motion detected
        locks[i] = 1;       // All doors Locked
    }
}

void toggleLight(int lights[], int rooms) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);
    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }
    lights[room - 1] = !lights[room - 1];
    printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
}

void readTemperature(int temp[], int rooms) {
    int room;
    printf("Enter room number to check temperature (1-%d): ", rooms);
    scanf("%d", &room);
    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }
    printf("Temperature in Room %d: %d°C\n", room, temp[room - 1]);
}

void checkMotion(int motion[], int rooms) {
    int room;
    printf("Enter room number to check motion (1-%d): ", rooms);
    scanf("%d", &room);
    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }
    printf("Motion in Room %d: %s\n", room, motion[room - 1] ? "Detected" : "No Motion");
}

void lockUnlockSecurity(int locks[], int rooms) {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", rooms);
    scanf("%d", &room);
    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }
    locks[room - 1] = !locks[room - 1];
    printf("Security lock in Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
}

void houseStatus(int lights[], int temp[], int motion[], int locks[], int rooms) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("- Room %d: Light %s, Temp %d°C, %s, %s\n",
               i + 1,
               lights[i] ? "ON" : "OFF",
               temp[i],
               motion[i] ? "Motion Detected" : "No Motion",
               locks[i] ? "Locked" : "Unlocked");
    }
}
