#include <stdio.h>

int main()
{
    int item;
    float price_per_item;
    char currency;

    // printf("Enter  item = \n");
    scanf("%d" , &item);

    // printf("Enter price per item = \n");
    scanf("%f " , &price_per_item);

    // printf("Enter currency = \n");
    
    scanf("%c", &currency);

    // output
    printf("Total Cost = %f  %c", item * price_per_item, currency);



    return 0;
}



