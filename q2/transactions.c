#include <stdio.h>


/*prototypes*/
void clean_buffer(void);
void transact(int choice, double *balance, int *deposits, int *withdrawals);

int main()
{
    /*variables*/ 
    double balance = 0.0;
    int deposits = 0;
    int withdrawals = 0;
    int choice;

    printf("\n===== MOBILE MONEY TRANSACTION SYSTEM =====\n");
    printf("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Transaction Summary\n5. Exit\n");

    /*big while loop to keep the user in the session until they exit the application*/
    while (1) {
        /*get user input*/
        printf("\nENter choice: ");

        /*read and store the input in choice. check if the return value is not 1, the user did not enter a number*/
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid. Please enter a number(1 to 5)\n");
            /*clear the user's input from the buffer*/
            clean_buffer();
            continue;
        }

        /*quit the loop if the user selects 5. this will end the program*/
        if (choice == 5) {
            printf("System terminated\n");
            break;
        }

        /*pass these variables into the transact function to process the user's choice */
        transact(choice, &balance, &deposits, &withdrawals);
    }
    return 0;
} 

/*This function handles: deposits, populating the balance, and transaction summary */
void transact(int choice, double *balance, int *deposits, int *withdrawals) {
    /*declare the amount variable*/
    double amount;

    /*this switch case passes the choice variable to process the what the user chooses*/
    switch (choice) {
        /*deposit*/
        case 1:
            printf("Enter deposit amount: ");

            /*check the return value of scanf*/
            if (scanf("%lf", &amount) != 1) {
                printf("\nInvalid. Please choose a number\n");
                /*clean the buffer*/
                clean_buffer();
                break;
            } 
            /*check if the user is not entering 0 or a negative value*/
            if (amount <= 0) {
                printf("Transaction rejected: enter an amount greater than 0\n");
                break;
            } 
            /*if all the checks pass, populate the balance and add 1 to the number of deposits*/
            *balance += amount;
            (*deposits)++;
            printf("Deposit successful\n");
            /*print balance*/
            printf("Current Balance: %.2f RWF\n", *balance);
            break;
        
        /*withdrawal*/    
        case 2:
            printf("Enter withdrawal amount: ");

            /*check the return value of scanf*/
            if (scanf("%lf", &amount) != 1) {
                printf("\nInvalid. Please choose a number\n");
                /*clean the buffer*/
                clean_buffer();
                break;
            } 
            /*check if the user is not entering 0 or a negative value*/
            if (amount <= 0) {
                printf("Transaction rejected: enter an amount greater than 0\n");
                break;
            } 
            /*obviously a user cannot withdraw what they don't have*/
            if (amount > *balance) {
                printf("Transaction rejected: Insufficient balance\n");
                break;
            }
            /*if all the checks pass, reduce the balance and add 1 to the number of withdrawals*/
            *balance -= amount;
            (*withdrawals)++;
            printf("Withdrawal successful\n");
            /*print balance*/
            printf("Current Balance: %.2f RWF\n", *balance);
            break;

        /*balance*/    
        case 3:
            printf("Current balance: %.2f RWF\n", *balance);
            break;

        /*transaction summary*/    
        case 4:
            printf("\n-----Transaction Summary-----\n");
            printf("%d total transaction this session\n", (*deposits + *withdrawals));
            printf("%d sucessful deposits\n", *deposits);
            printf("%d sucessful withdrawals\n", *withdrawals);
            printf("YOur total balance is: %.2f\n", *balance);
            break;
        
        default:
            printf("Invalid. Choose a number from 1 to 5\n");
            break;
    }
}

/*this function removes from the buffer whatever the user inputes that we don't like*/
void clean_buffer(void) {
    int character;
    do {
        character = getchar();
    } while (character != '\n' && character != EOF);
}
