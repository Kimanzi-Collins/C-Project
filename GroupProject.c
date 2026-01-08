//GitHub Repository Link: https://github.com/Kimanzi-Collins/C-Project
//SCS3/2490/2025
//SCS3/9999/2025
//SCS3/2589/2025
//SCS3/150356/2025
#include <stdio.h>

int main(){
    int choice;
    do{
        printf("***************************************************************\n");
        printf("-------------Daily Transport Tracker-------------\n");
        printf("Welcome to the Daily Transport Tracker System!\n");
        printf("This system helps you track daily transport expenses efficiently.\n");
        printf("You can log your daily transport costs and generate reports as needed.\n");
        printf("Please select an option:\n");
        printf("1. Log Daily Transport Expense\n");
        printf("2. Generate Expense Report\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Logging daily transport expense...\n");
                logExpense();
                break;
            case 2:
                printf("Generating expense report...\n");
                generateReport();
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);
}
    