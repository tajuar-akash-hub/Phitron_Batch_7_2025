// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

void fun(int * &p){  // &p to pass the same pointer, otherwise it will be copy one 

    int y = 80;
    // *p = 100;

    p = &y;

    cout<<"from fun" << " " << *p << endl;

}

int main()
{
    int x = 50;

    int *p = &x;

     fun(p);

    

    cout <<" from main "<<" " << *p;

    cout<<endl;

   
    
}