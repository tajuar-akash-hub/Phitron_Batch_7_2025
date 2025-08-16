// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node{

    public:

    int value;
    node * next;

    node(int v){
        this->value = v;
        this->next = NULL;
    }


};
int main()
{

    // my_class my_obj = my_class("Akash");

    node my_obj_1(10),my_obj_2(20) , my_obj_3(30);

    //address

    // head = my_obj_1

    my_obj_1.next = &my_obj_2;
    my_obj_2.next = &my_obj_3;
   




    cout<< my_obj_1.value << endl;
    cout<< my_obj_1.next->value<<endl;
    cout << my_obj_1.next->next->value;  

    // -> means, (*node_1.value) we are defrencing the object's address to access those values



    
}