#include "tkf.h"

void calculateBill(Customer *customer)
{
    customer->subtotal = 0.0f;

    /* Calculate subtotal */
    for (int i = 0; i < customer->cartCount; i++)
    {
        customer->subtotal += customer->cart[i].totalPrice;
    }

    /* Member discount */
    if (strcmp(customer->memberStatus, "Member") == 0)
    {
        customer->discount = customer->subtotal * 0.10f;
    }
    else
    {
        customer->discount = 0.0f;
    }

    /* Service tax (Dine-In only) */
    if (strcmp(customer->orderMethod, "Dine-In") == 0)
    {
        customer->serviceTax = (customer->subtotal - customer->discount) * 0.10f;
    }
    else
    {
        customer->serviceTax = 0.0f;
    }

    /* Government tax */
    customer->governmentTax =
        (customer->subtotal - customer->discount) * 0.06f;

    /* Final total */
    customer->finalTotal =
        customer->subtotal
        - customer->discount
        + customer->serviceTax
        + customer->governmentTax;
}

void paymentProcess(Customer *customer)
{
    int choice;

    printf("\n");
    printf("=========== PAYMENT ===========\n");
    printf("1. Cash\n");
    printf("2. Debit / Credit Card\n");
    printf("3. E-Wallet\n");
    printf("===============================\n");

    printf("Choose payment method: ");
    scanf("%d", &choice);
    clearInputBuffer();

    switch (choice)
    {
        case 1:
            strcpy(customer->paymentMethod, "Cash");

            do
            {
                printf("Cash Received (RM): ");
                scanf("%f", &customer->payment);
                clearInputBuffer();

                if (customer->payment < customer->finalTotal)
                {
                    printf("Insufficient payment.\n");
                }

            } while (customer->payment < customer->finalTotal);

            customer->change =
                customer->payment - customer->finalTotal;

            break;

        case 2:
            strcpy(customer->paymentMethod, "Card");
            customer->payment = customer->finalTotal;
            customer->change = 0.0f;
            break;

        case 3:
            strcpy(customer->paymentMethod, "E-Wallet");
            customer->payment = customer->finalTotal;
            customer->change = 0.0f;
            break;

        default:
            printf("Invalid option.\n");
            paymentProcess(customer);
            return;
    }
}