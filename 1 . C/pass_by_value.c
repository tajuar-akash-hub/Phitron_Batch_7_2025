#include <stdio.h>

void fun(int *n){
    *n = 0;
    printf("Inside fun %d\n",*n);

}

int main()
{

    int n; 
    scanf("%d",&n);
    
    fun(&n);  //pass by reference 
    printf("Inside Main %d\n",n);

    return 0;
}