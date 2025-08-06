#include <stdio.h>
int fun()
{
    

    int n;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("end of fun\n");
    return a;
}

int array_print(int n,int a[]){
    printf("inside array-print\n");

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

void m(int *p){
    for(int i=0;i<5;i++){
        printf("%d ",p[i]);
    }
}

int main()
{
    
    // int *ptr = fun();

    // printf("%d",*ptr);

    // int a[5]={1,2,3,4,5};
    // array_print(5,a);
    int a[5]= {6,5,3};
    // m(a);
    printf("%d",*a);


    return 0;
}