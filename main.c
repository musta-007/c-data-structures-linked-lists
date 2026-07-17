#include "functions.h"
#include <stdio.h>

int main() 
{
    Node* head = NULL;
    Node* start = NULL;
    int choice;
    char num_plaque[20];
    char model[20];
    int available;

    do {
        printf("\n*****************************Taxi Management System\n");
        printf("1. Add Taxi\n");
        printf("2. Remove Taxi\n");
        printf("3. Update Taxi\n");
        printf("4. Print Available Taxis\n");
        printf("5. Print Unavailable Taxis\n");
        printf("6. Print All Taxis\n");
        printf("7. Reserve Taxi\n");
        printf("8. Cancel Reservation\n");
        printf("9. Print Reserved Taxis\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter plaque number: ");
                scanf("%s", num_plaque);
                printf("Enter model: ");
                scanf("%s", model);
                printf("Is the taxi available? (1 for yes, 0 for no): ");
                scanf("%d", &available);
                head = add_taxi(head, num_plaque, model, available);
                break;
            case 2:
                printf("Enter plaque number to remove: ");
                scanf("%s", num_plaque);
                head = remove_taxi(head, num_plaque);
                break;
            case 3:
                printf("Enter plaque number to update: ");
                scanf("%s", num_plaque);
                printf("Enter new model: ");
                scanf("%s", model);
                printf("Is the taxi available? (1 for yes, 0 for no): ");
                scanf("%d", &available);
                head = update_taxi(head, num_plaque, model, available);
                break;
            case 4:
                print_taxis_available(head);
                break;
            case 5:
                print_taxis_unavailable(head);
                break;
            case 6:
                print_all_taxis(head);
                break;
            case 7:
                printf("Enter plaque number to reserve: ");
                scanf("%s", num_plaque);
                start = reservation(head, start, num_plaque);
                break;
            case 8:
                printf("Enter plaque number to cancel reservation: ");
                scanf("%s", num_plaque);
                start = cancel_reservation(head, start, num_plaque);
                break;
            case 9:
                print_reserved_taxis(start);
                break;
            case 10:
                free_taxis(head, start);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 10);

    return 0;
}