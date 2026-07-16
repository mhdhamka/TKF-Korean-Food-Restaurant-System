#include "tkf.h"

void getCurrentDateTime(char buffer[])
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(buffer, 50, "%d/%m/%Y %H:%M:%S", t);
}

void generateReceipt(Customer customer)
{
    /* Reserved for future use if you want
       automatic receipt number generation */
}

void printReceipt(Customer customer)
{
    char dateTime[50];
    getCurrentDateTime(dateTime);

    printf("\n");
    printf("========================================================\n");
    printf("                 TKF KOREAN RESTAURANT\n");
    printf("========================================================\n");

    printf("Date           : %s\n", dateTime);
    printf("Receipt No     : %s\n", customer.receiptNo);
    printf("Member Status  : %s\n", customer.memberStatus);
    printf("Order Method   : %s\n", customer.orderMethod);
    printf("Payment Method : %s\n", customer.paymentMethod);

    printf("--------------------------------------------------------\n");
    printf("%-3s %-22s %-8s %-5s %-8s\n",
           "No", "Item", "Size", "Qty", "Total");

    printf("--------------------------------------------------------\n");

    for (int i = 0; i < customer.cartCount; i++)
    {
        printf("%-3d %-22s %-8s %-5d RM%-7.2f\n",
               i + 1,
               customer.cart[i].foodName,
               customer.cart[i].size,
               customer.cart[i].quantity,
               customer.cart[i].totalPrice);
    }

    printf("--------------------------------------------------------\n");

    printf("%-35s RM %8.2f\n", "Subtotal", customer.subtotal);
    printf("%-35s RM %8.2f\n", "Member Discount", customer.discount);
    printf("%-35s RM %8.2f\n", "Service Tax", customer.serviceTax);
    printf("%-35s RM %8.2f\n", "Government Tax", customer.governmentTax);

    printf("========================================================\n");
    printf("%-35s RM %8.2f\n", "TOTAL", customer.finalTotal);
    printf("%-35s RM %8.2f\n", "Amount Paid", customer.payment);
    printf("%-35s RM %8.2f\n", "Change", customer.change);
    printf("========================================================\n");

    printf("\nThank you for dining with TKF Restaurant!\n");
}