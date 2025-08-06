#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int range = ((n + 1) / 2) + 5;

    for (int i = 1; i <= range; i++)
    {
        // for space
        for (int s = (range - i) - 1; s >= 0; s--)
        {
            printf(" ");
        }

        // star print

        for (int star = 0; star < 2 * i - 1; star++)
        {
            printf("*");
        }

        printf("\n");
    }

    // second half

    for (int i = 1; i <= 5; i++)
    {

        // space are fixed

        for (int space = 1; space <= 5; space++){
            printf(" ");

        }

        //start print
        for(int star=1;star<=n;star++){

            printf("*");

        }

        printf("\n");
    }

    return 0;
}