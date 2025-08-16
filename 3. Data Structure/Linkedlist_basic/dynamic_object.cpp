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

    // node my_obj_1(10),my_obj_2(20) , my_obj_3(30);

     // dynamic object 

    node* head = new node(10);
    node* a = new node(20);
    node* b = new node(30);

    //address

    head->next = a;
    a->next = b;

    cout<< head->value << endl;
    cout<< head->next->value << endl;
    cout << head->next->next->value;
     

    // -> means, (*node_1.value) we are defrencing the object's address to access those values


}