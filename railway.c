#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRAINS 10
#define MAX_SEATS_PER_TRAIN 50

typedef struct {
    int trainNumber;
    int seatNumber;
    char passengerName[50];
    char gender;
    int foodPreference;  // 1 for vegetarian, 2 for non-vegetarian
    int pnrNumber;
} Reservation;

typedef struct {
    int trainNumber;
    char trainName[50];
    int availableSeats;
} Train;

Train trains[MAX_TRAINS] = {
    {1, "NDLS Express", MAX_SEATS_PER_TRAIN},
    {2, "Chennai Express", MAX_SEATS_PER_TRAIN},
    {3, "UP EXPRESS", MAX_SEATS_PER_TRAIN},
    {4, "Bangalore Express", MAX_SEATS_PER_TRAIN},
    {5, "Haryana Express", MAX_SEATS_PER_TRAIN},
    {6, "Noida Express", MAX_SEATS_PER_TRAIN},
    {7, "Mumbai Express", MAX_SEATS_PER_TRAIN},
    {8, "Vande Bharat", MAX_SEATS_PER_TRAIN},
    {9, "Dehradun Express", MAX_SEATS_PER_TRAIN},
    {10, "Jammu Express", MAX_SEATS_PER_TRAIN}
};

Reservation reservations[MAX_TRAINS][MAX_SEATS_PER_TRAIN];
int totalReservations[MAX_TRAINS] = {0};

int generatePNR() {
    // Generating a random number for PNR
    return rand() % 9000 + 1000;
}

void displayTrains() {
    printf("\n-- Available Trains --\n");

    for (int i = 0; i < MAX_TRAINS; i++) {
        printf("%d. %s (Available Seats: %d)\n", trains[i].trainNumber, trains[i].trainName, trains[i].availableSeats);
    }
}

void displayMenu() {
    printf("\n1. Reserve a seat\n");
    printf("2. View reservations\n");
    printf("3. View reservations for a specific train\n");
    printf("4. Cancel a ticket\n");
    printf("5. Exit\n");
}

void reserveSeat() {
    displayTrains();

    int selectedTrain;
    printf("Enter the number of the train: ");
    scanf("%d", &selectedTrain);

    if (selectedTrain < 1 || selectedTrain > MAX_TRAINS) {
        printf("Invalid train selection.\n");
        return;
    }

    if (totalReservations[selectedTrain - 1] < MAX_SEATS_PER_TRAIN) {
        Reservation newReservation;

        printf("Enter passenger name: ");
        scanf("%s", newReservation.passengerName);

        printf("Enter gender (M/F): ");
        scanf(" %c", &newReservation.gender);

        printf("Enter food preference (1 for vegetarian, 2 for non-vegetarian): ");
        scanf("%d", &newReservation.foodPreference);

        newReservation.trainNumber = selectedTrain;
        newReservation.seatNumber = totalReservations[selectedTrain - 1] + 1;
        newReservation.pnrNumber = generatePNR();

        reservations[selectedTrain - 1][totalReservations[selectedTrain - 1]] = newReservation;
        totalReservations[selectedTrain - 1]++;

        printf("Reservation successful. Train: %s, Seat number: %d, PNR: %d\n",
               trains[selectedTrain - 1].trainName, newReservation.seatNumber, newReservation.pnrNumber);

        // Update available seats
        trains[selectedTrain - 1].availableSeats--;
    } else {
        printf("Sorry, all seats for this train are reserved.\n");
    }
}

void viewReservations() {
    printf("\n-- List of Reservations --\n");

    for (int i = 0; i < MAX_TRAINS; i++) {
        printf("\nTrain: %s\n", trains[i].trainName);

        for (int j = 0; j < totalReservations[i]; j++) {
            printf("Seat %d: %s, Gender: %c, Food: %s, PNR: %d\n", reservations[i][j].seatNumber,
                   reservations[i][j].passengerName, reservations[i][j].gender,
                   (reservations[i][j].foodPreference == 1) ? "Vegetarian" : "Non-Vegetarian", reservations[i][j].pnrNumber);
        }
    }
}

void viewReservationsForTrain() {
    int selectedTrain;
    displayTrains();
    printf("Enter the number of the train: ");
    scanf("%d", &selectedTrain);

    if (selectedTrain < 1 || selectedTrain > MAX_TRAINS) {
        printf("Invalid train selection.\n");
        return;
    }

    printf("\n-- Reservations for Train: %s --\n", trains[selectedTrain - 1].trainName);

    for (int j = 0; j < totalReservations[selectedTrain - 1]; j++) {
        printf("Seat %d: %s, Gender: %c, Food: %s, PNR: %d\n", reservations[selectedTrain - 1][j].seatNumber,
               reservations[selectedTrain - 1][j].passengerName, reservations[selectedTrain - 1][j].gender,
               (reservations[selectedTrain - 1][j].foodPreference == 1) ? "Vegetarian" : "Non-Vegetarian",
               reservations[selectedTrain - 1][j].pnrNumber);
    }
}

void cancelTicket() {
    int cancelPNR;
    printf("Enter the PNR number of the ticket to cancel: ");
    scanf("%d", &cancelPNR);

    for (int i = 0; i < MAX_TRAINS; i++) {
        for (int j = 0; j < totalReservations[i]; j++) {
            if (reservations[i][j].pnrNumber == cancelPNR) {
                printf("Ticket canceled for Train: %s, Seat %d, PNR: %d\n", trains[i].trainName, reservations[i][j].seatNumber, reservations[i][j].pnrNumber);

                trains[i].availableSeats++;
                for (int k = j; k < totalReservations[i] - 1; k++) {
                    reservations[i][k] = reservations[i][k + 1];
                }

                totalReservations[i]--;
                
                printf("Cancellation successful.\n");
                return;
            }
        }
    }

    printf("Ticket with PNR %d not found.\n", cancelPNR);
}

int main() {
    srand(time(NULL));

    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reserveSeat();
                break;
            case 2:
                viewReservations();
                break;
            case 3:
                viewReservationsForTrain();
                break;
            case 4:
                cancelTicket();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
