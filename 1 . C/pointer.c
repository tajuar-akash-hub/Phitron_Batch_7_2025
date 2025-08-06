#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    int *p = &n;
    printf("Here's the address %p",p);
  

    return 0;
}