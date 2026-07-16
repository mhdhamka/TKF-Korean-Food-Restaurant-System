#include "tkf.h"



void saveTransaction(Customer customer)
{

    FILE *file;


    file = fopen("TransactionRecord.txt","a");


    if(file == NULL)
    {
        printf("Unable to open transaction file.\n");
        return;
    }



    fprintf(file,"\n");
    fprintf(file,"====================================================\n");
    fprintf(file,"              TKF KOREAN RESTAURANT\n");
    fprintf(file,"====================================================\n");


    fprintf(file,"Receipt No     : %s\n",
            customer.receiptNo);


    fprintf(file,"Member Status  : %s\n",
            customer.memberStatus);


    fprintf(file,"Order Method   : %s\n",
            customer.orderMethod);


    fprintf(file,"Payment Method : %s\n",
            customer.paymentMethod);



    fprintf(file,"----------------------------------------------------\n");


    fprintf(file,
            "%-5s %-25s %-10s %-5s %-10s\n",
            "No",
            "Food",
            "Size",
            "Qty",
            "Total");



    fprintf(file,"----------------------------------------------------\n");



    for(int i=0;i<customer.cartCount;i++)
    {

        fprintf(file,
                "%-5d %-25s %-10s %-5d RM%.2f\n",
                i+1,
                customer.cart[i].foodName,
                customer.cart[i].size,
                customer.cart[i].quantity,
                customer.cart[i].totalPrice);

    }



    fprintf(file,"----------------------------------------------------\n");


    fprintf(file,"Subtotal          : RM %.2f\n",
            customer.subtotal);


    fprintf(file,"Discount          : RM %.2f\n",
            customer.discount);


    fprintf(file,"Service Tax       : RM %.2f\n",
            customer.serviceTax);


    fprintf(file,"Government Tax    : RM %.2f\n",
            customer.governmentTax);


    fprintf(file,"Final Total       : RM %.2f\n",
            customer.finalTotal);


    fprintf(file,"Payment           : RM %.2f\n",
            customer.payment);


    fprintf(file,"Change            : RM %.2f\n",
            customer.change);



    fprintf(file,"====================================================\n");



    fclose(file);


    printf("\nTransaction saved successfully.\n");

}






void viewTransaction()
{

    FILE *file;


    char line[200];



    file=fopen("TransactionRecord.txt","r");



    if(file==NULL)
    {

        printf("\nNo transaction record found.\n");

        return;

    }



    printf("\n");
    printf("====================================================\n");
    printf("              TRANSACTION HISTORY\n");
    printf("====================================================\n");



    while(fgets(line,sizeof(line),file))
    {

        printf("%s",line);

    }



    fclose(file);

}