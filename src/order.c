#include "tkf.h"



void addToCart(Customer *customer, Menu menu[], int menuCount)
{

    int choice;
    int quantity;

    char size[10];


    if(customer->cartCount >= MAX_CART)
    {
        printf("Cart is full.\n");
        return;
    }



    printf("\nEnter menu ID: ");
    scanf("%d",&choice);

    clearInputBuffer();



    if(choice < 1 || choice > menuCount)
    {
        printf("Invalid menu selection.\n");
        return;
    }



    printf("Choose size (R/L): ");

    scanf("%s",size);

    clearInputBuffer();



    printf("Quantity: ");

    scanf("%d",&quantity);

    clearInputBuffer();



    float price;



    if(size[0]=='R' || size[0]=='r')
    {
        strcpy(size,"Regular");

        price = menu[choice-1].regularPrice;

    }

    else if(size[0]=='L' || size[0]=='l')
    {
        strcpy(size,"Large");

        price = menu[choice-1].largePrice;

    }

    else
    {
        printf("Invalid size.\n");
        return;
    }




    CartItem *item =
    &customer->cart[customer->cartCount];



    item->menuID = menu[choice-1].id;



    strcpy(item->foodName,
           menu[choice-1].name);



    strcpy(item->size,size);



    item->quantity = quantity;



    item->price = price;



    item->totalPrice = price * quantity;



    customer->cartCount++;



    printf("\n%s added to cart.\n",
           item->foodName);

}





void removeFromCart(Customer *customer)
{

    int remove;



    if(customer->cartCount==0)
    {
        printf("Cart is empty.\n");
        return;
    }



    displayCart(*customer);



    printf("\nRemove item number: ");

    scanf("%d",&remove);

    clearInputBuffer();



    if(remove < 1 ||
       remove > customer->cartCount)
    {
        printf("Invalid selection.\n");
        return;
    }



    for(int i=remove-1;
        i<customer->cartCount-1;
        i++)
    {

        customer->cart[i]
        =
        customer->cart[i+1];

    }



    customer->cartCount--;



    printf("Item removed successfully.\n");

}





void displayCart(Customer customer)
{

    printf("\n");
    printf("====================================================\n");
    printf("                    SHOPPING CART\n");
    printf("====================================================\n");


    if(customer.cartCount==0)
    {
        printf("Cart is empty.\n");
        return;
    }



    printf("%-5s %-25s %-10s %-8s %-10s\n",
           "No",
           "Food",
           "Size",
           "Qty",
           "Price");



    printf("----------------------------------------------------\n");



    for(int i=0;i<customer.cartCount;i++)
    {

        printf("%-5d %-25s %-10s %-8d RM%.2f\n",
               i+1,
               customer.cart[i].foodName,
               customer.cart[i].size,
               customer.cart[i].quantity,
               customer.cart[i].totalPrice);

    }

    printf("====================================================\n");

}