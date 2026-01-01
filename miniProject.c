#include <stdio.h>

#define TOTAL_SEATS 10

int seats[TOTAL_SEATS];   // 1D array for seats

// Function to display seat status
void displaySeats() {
    int i;
    printf("\nSeat Status:\n");
    for (i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] == 0)
            printf("Seat %d : Available\n", i + 1);
        else
            printf("Seat %d : Booked\n", i + 1);
    }
}

// Function to book a seat
void bookSeat() {
    int seatNo;
    printf("Enter seat number to book (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNo);

    if (seatNo < 1 || seatNo > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
    } else if (seats[seatNo - 1] == 1) {
        printf("Seat already booked!\n");
    } else {
        seats[seatNo - 1] = 1;
        printf("Seat %d booked successfully!\n", seatNo);
    }
}

// Function to cancel a seat
void cancelSeat() {
    int seatNo;
    printf("Enter seat number to cancel (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNo);

    if (seatNo < 1 || seatNo > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
    } else if (seats[seatNo - 1] == 0) {
        printf("Seat is already available!\n");
    } else {
        seats[seatNo - 1] = 0;
        printf("Seat %d cancelled successfully!\n", seatNo);
    }
}

int main() {
    int choice, i;

    // Initialize all seats as available
    for (i = 0; i < TOTAL_SEATS; i++) {
        seats[i] = 0;
    }

    do {
        printf("\n--- Railway Ticket Booking System ---\n");
        printf("1. Display Seats\n");
        printf("2. Book Seat\n");
        printf("3. Cancel Seat\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                cancelSeat();
                break;
            case 4:
                printf("Thank you for using the system!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
