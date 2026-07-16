#include "tkf.h"

int main()
{
    Menu menu[MAX_MENU];

    int menuCount = 0;
    Customer customers[MAX_CUSTOMER];
    int customerCount = 0;
    int choice;

    initializeMenu(menu, &menuCount);

    do
    {
        printf("\n");
        printf("====================================\n");
        printf("        TKF KOREAN RESTAURANT\n");
        printf("====================================\n");
        printf("1. Customer Order\n");
        printf("2. View Menu\n");
        printf("3. Search Food\n");
        printf("4. Transaction History\n");
        printf("5. Admin Panel\n");
        printf("6. Exit\n");
        printf("====================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice)
        {
            case 1:
            {
                Customer customer;
                customer.cartCount = 0;

                generateReceipt(customer);
                printf("\nMember? (Y/N): ");

                char member;

                scanf("%c",&member);
                clearInputBuffer();

                if(member=='Y'||member=='y')
                {
                    strcpy(customer.memberStatus,"Member");
                }
                else
                {
                    strcpy(customer.memberStatus,"Non Member");
                }

                printf("Order method\n");
                printf("1. Dine-In\n");
                printf("2. Takeaway\n");
                printf("Choice: ");


                int method;

                scanf("%d",&method);
                clearInputBuffer();

                if(method==1)
                {
                    strcpy(customer.orderMethod,"Dine-In");
                }
                else
                {
                    strcpy(customer.orderMethod,"Takeaway");
                }

                int orderChoice;

                do
                {
                    displayMenu(menu,menuCount);
                    addToCart(&customer,menu,menuCount);

                    printf("\nAdd another item?\n");
                    printf("1. Yes\n");
                    printf("2. Checkout\n");
                    printf("Choice: ");
                    scanf("%d",&orderChoice);
                    clearInputBuffer();

                }while(orderChoice==1);

                displayCart(customer);
                calculateBill(&customer);
                paymentProcess(&customer);
                printReceipt(customer);
                saveTransaction(customer);

                customers[customerCount]=customer;
                customerCount++;
                break;
            }

            case 2:

                displayMenu(menu,menuCount);
                break;

            case 3:

                searchMenu(menu,menuCount);
                break;

            case 4:

                viewTransaction();
                break;

            case 5:

                adminPanel(menu,&menuCount);
                break;

            case 6:

                printf("\nThank you for using TKF Restaurant.\n");

                break;

            default:
                printf("\nInvalid option.\n");
        }
    }while(choice!=6);
    return 0;
}