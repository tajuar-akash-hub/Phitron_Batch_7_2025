#include <stdio.h>

void mello(){
    printf("Mello\n");
}

void gello(){
    printf("Gello\n");
    mello();

}

void helllo(){

    printf("Hello\n");
    gello();
}

// void print_1_to_N(int n){
//     printf("%d\n",n);

//     if(n==5) return;
//     print_1to_N(n+1);

// }

void print_N_to_1(int n){

    if(n==6) return ;

    print_N_to_1(n+1);

    printf("%d\n",n);
    
}
int main()
{
    // printf("HI\n");
    // helllo();
    // printf("ami shesh\n");
    print_N_to_1(1);


    return 0;
}