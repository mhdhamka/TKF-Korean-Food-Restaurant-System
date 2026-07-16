#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tkf.h"


int main()
{

    Menu menu[MENU_SIZE] =
    {
        {"Bibimbap",10.00,15.00},
        {"Korean Fried Chicken",9.00,14.00},
        {"Bulgogi",8.50,13.50},
        {"Japchae",8.50,13.50},
        {"Hameul Pajeon",7.00,12.00}
    };
    Customer *customers = NULL;

    int totalCustomer = 0;
    int option;
    char again;

    do
    {

        printf("\n==============================\n");
        printf(" TKF Restaurant System\n");
        printf("==============================\n");

        printf("1. Make Order\n");
        printf("2. Transaction Record\n");
        printf("3. Exit\n");

        printf("Select option: ");
        scanf("%d",&option);



        if(option == 1)
        {

            customers =
            realloc(customers,
            (totalCustomer+1)*sizeof(Customer));

            Customer *current =
            &customers[totalCustomer];
            current->receiptNo =
            totalCustomer+1;
            current->totalOrder=0;

            char member;
            char method;

            printf("Member? (Y/N): ");
            scanf(" %c",&member);

            if(member=='Y'||member=='y')
                strcpy(current->memberStatus,"Member");

            else
                strcpy(current->memberStatus,"Non Member");

            printf("Dine-In or Takeaway? (D/T): ");
            scanf(" %c",&method);

            if(method=='D'||method=='d')
                strcpy(current->methodStatus,"Dine-In");

            else
                strcpy(current->methodStatus,"Takeaway");

            displayMenu(menu);

            while(current->totalOrder < MAX_ORDER)
            {
                addOrder(current,menu);

                char more;

                printf("Add another order? (Y/N): ");
                scanf(" %c",&more);

                if(more=='N'||more=='n')
                    break;

                displayMenu(menu);
            }

            calculateBill(current);
            displayReceipt(*current);

            totalCustomer++;
        }

        else if(option==2)
        {
            displayTransaction(customers,totalCustomer);
        }

        else if(option==3)
        {
            saveTransaction(customers,totalCustomer);
            printf("Transaction saved.\n");
            break;
        }

        printf("\nContinue? (Y/N): ");
        scanf(" %c",&again);

    }while(again=='Y'||again=='y');

    free(customers);
    return 0;
}
