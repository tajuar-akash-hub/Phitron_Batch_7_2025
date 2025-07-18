// #include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void declare_dynamic_variable_using_malloc()
{
    int *ptr = (int *)malloc(200);
    /*
  without int* (type casting) it returns a void* or generic pointer
  , so we need to type cast it integer type pointer, C automatically
  does it, but cpp can't!
    */
    cin >> *ptr;
    cout << *ptr;
}

void declare_dynamic_variable_using_new()
{
    int *ptr = new int;
    cin >> *ptr;
    cout << *ptr;
}

// prove that stack memory disappers and heap stays

int *f1; // global
int *f2;

void fun()
{
    int x = 10;
    f1 = &x;

    printf("Address of f1 %p\n", f1);
    printf("value of f1 %d\n", *f1);
    printf("function ends----\n");
    return;
}

void fun2()
{
    int *x = new int;
    *x = 100;
    f2 = x;
    return;
}

// dynamic array declare
void dynamic_array_declare()
{

    int *a = new int[5];

    for (int i = 0; i < 5; i++)
    {
        // cin>>a[i];
        cin >> *(a + i); // same as a[i]
    }

    for (int i = 0; i < 5; i++)
    {
        // cout<<a[i]<<" ";
        cout << *(a + i) << " ";
    }
}

// return array from a function

int *return_array_from_a_fun()
{

    int *a = (int *)malloc(sizeof(int) * 5);
    //  int* a =  new int[5];

    for (int i = 0; i < 5; i++)
    {
        // cin>>a[i];
        cin >> *(a + i); // same as a[i]
    }

    // for(int i=0;i<5;i++){
    //     // cout<<a[i]<<" ";
    //     cout<<*(a+i)<<" ";
    // }

    return a;
}

void increase_size_of_dynamic_array()
{
    /*
    Steps 1) copy dynamic array to another  dynamic array with increased size
    2) delete the first dynamic array , delete[] array;
    3)
    */
    int *a1 = new int[5];

    for (int i = 0; i < 5; i++)
    {
        // cin>>a[i];
        cin >> *(a1 + i); // same as a[i]
    }



    int* a2 = new int[7];


    // copy a1 to a2 

     for (int i = 0; i < 5; i++)
    {
        a2[i] = a1[i];
    }

    // delete the a1 array 
    delete[] a1;

    a2[5]= 1;
    a2[6]= 2;


    for (int i = 0; i < 7; i++)
    {
        // cin>>a[i];
        cout << *(a2 + i) <<" " ; // same as a[i]
    }
}

int main()
{
    // declare_dynamic_variable();
    // declare_dynamic_variable_using_malloc();

    // fun();
    // // fun2();
    // printf("Address of f1 %p\n",f1);
    // printf("value of f1 %d\n",*f1);

    // printf("Address of f2 %p\n",f2);
    // printf("value of f2 %d\n",*f2);

    // dynamic_array_declare();

    // int *array = return_array_from_a_fun();

    // for (int i = 0; i < 5; i++)
    // {

    //     // cout<<*(array+i) <<" ";
    //     cout << array[i] << " ";
    // }

    increase_size_of_dynamic_array();

    return 0;
}