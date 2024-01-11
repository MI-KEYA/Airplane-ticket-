#include<string.h>
#define MAX_SEAT 9

char availableSeat[MAX_SEAT][3]={
    "1A", "1B", "1C",
    "2A", "2B", "2C",
    "3A", "3B", "3C"
};
int bookedSeat[MAX_SEAT] = {0};

void displayAvailableSeat(){
    int i, count=0;
    printf("Available Seats: \n");
    for(i=0;i<MAX_SEAT;i++){
            if(bookedSeat[i]==1){
                printf("X ");
            }else{
                 printf("%s ",availableSeat[i]);
            }
            count++;
            if(count%3==0){
                printf("\n");
            }
    }
    printf("\n");
}


int bookSeat(char *seat){
    int payment;
    int bkash, nagad;
    int i;
    for(i=0;i<MAX_SEAT;i++){
        if(strcmp(availableSeat[i],seat)==0 && bookedSeat[i] == 0){
            bookedSeat[i] = 1;
            printf("Enter 1 for bkash and 2 for Nagad: ");
            scanf("%d",&payment);
            switch(payment){

            case 1:
                printf("Enter Bkash Number: ");
                scanf("%d", &bkash);
                break;
            case 2:
                printf("Enter Nagad Number: ");
                scanf("%d",&nagad);
                break;
            default:
                printf("Invalid option");
            }

            return 1;
        }
    }
    return 0;
}
int cancelSeat(char *seat){
    int i;
    for(i=0;i<MAX_SEAT;i++){
        if(strcmp(availableSeat[i], seat)==0 && bookedSeat[i]==1){
        bookedSeat[i] = 0;
        return 1;
        }
    }
    return 0;
}

void viewBookedTickets(){
    printf("Booked Seats: \n");
    int i;
    for(i=0;i<MAX_SEAT;i++){
        if(bookedSeat[i]==1){
            printf("%s ",availableSeat[i]);
        }
    }
    printf("\n");
}

// MENU


void showMenu() {
    printf("\n");
    printf("\t\t    Menu\n");
    printf("\t\t  =========\n");
    printf("1. Book a Ticket\n");
    printf("2. Cancel a Ticket\n");
    printf("3. View Booked Tickets\n");
    printf("4. Exit\n");
    printf("\n");
}

void MenuOption(int option) {
    switch (option) {
        case 1:
            printf("Book a Ticket\n");
            bookTicket();
            break;
        case 2:
            printf("Cancel a Ticket\n");
            cancelTicket();
            break;
        case 3:
            printf("View Booked Tickets\n");
            viewBookedTickets();
            break;
        case 4:
            printf("Exiting...  Thank you\n");

            break;
        default:
            printf("Invalid option\n");
            break;
    }
}

void bookTicket() {
    displayAvailableSeat();

    char seat[3];

    printf("Enter the seat number to book (e.g., 1A): ");
    scanf("%s", seat);


    if (bookSeat(seat)) {
        printf("Ticket booked successfully! Thank you for purchasing...\n");
    } else {
        printf("Failed to book the ticket. The seat may be already booked or invalid.\n");
    }
}

void cancelTicket() {

        char seat[3];
        printf("Enter the seat number to cancel (e.g., 1A): ");
        scanf("%s", seat);

        if (cancelSeat(seat)) {
            printf("Ticket canceled successfully!\n");
        } else {
            printf("Failed to cancel the ticket. The seat may be already canceled or invalid.\n");
        }
      }

