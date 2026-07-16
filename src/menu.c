#include "tkf.h"

void initializeMenu(Menu menu[], int *menuCount)
{

    Menu defaultMenu[] =
    {

        {1, "Bibimbap", "Rice", 10.00, 15.00, 0},

        {2, "Korean Fried Chicken", "Chicken", 9.00, 14.00, 0},

        {3, "Bulgogi", "Meat", 8.50, 13.50, 0},

        {4, "Japchae", "Noodles", 8.50, 13.50, 0},

        {5, "Hameul Pajeon", "Pancake", 7.00, 12.00, 0}

    };



    int size = sizeof(defaultMenu) / sizeof(defaultMenu[0]);


    for(int i = 0; i < size; i++)
    {
        menu[i] = defaultMenu[i];
    }


    *menuCount = size;

}

void displayMenu(Menu menu[], int menuCount)
{

    printf("\n");
    printf("====================================================\n");
    printf("                 TKF FOOD MENU\n");
    printf("====================================================\n");


    printf("%-5s %-30s %-15s %-10s %-10s\n",
           "ID",
           "Food",
           "Category",
           "Regular",
           "Large");


    printf("----------------------------------------------------\n");


    for(int i = 0; i < menuCount; i++)
    {

        printf("%-5d %-30s %-15s RM%-8.2f RM%-8.2f\n",
               menu[i].id,
               menu[i].name,
               menu[i].category,
               menu[i].regularPrice,
               menu[i].largePrice);

    }


    printf("====================================================\n");

}

void searchMenu(Menu menu[], int menuCount)
{

    char keyword[50];

    printf("\nEnter food name to search: ");
    fgets(keyword,sizeof(keyword),stdin);

    keyword[strcspn(keyword,"\n")] = '\0';

    int found = 0;

    printf("\nSearch Result:\n");

    printf("----------------------------------------------\n");

    for(int i=0;i<menuCount;i++)
    {

        if(strstr(menu[i].name,keyword)!=NULL)
        {

            printf("%d. %s (%s)\n",
                   menu[i].id,
                   menu[i].name,
                   menu[i].category);

            printf("Regular : RM%.2f\n",
                   menu[i].regularPrice);

            printf("Large   : RM%.2f\n",
                   menu[i].largePrice);

            printf("----------------------------------------------\n");


            found = 1;

        }

    }

    if(found==0)
    {
        printf("Food not found.\n");
    }

}