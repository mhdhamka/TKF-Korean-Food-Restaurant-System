#include "tkf.h"


void clearInputBuffer()
{
    int c;

    while((c = getchar()) != '\n' && c != EOF);
}