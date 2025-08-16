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

void print_linked_list(node * head){

    node * temp = head;  // its not a copy, its hold the memory address of head

    while(temp!=NULL){
        cout<<temp->value<<endl;
        temp = temp->next;
    }

}

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

    // cout<< head->value << endl;
    // cout<< head->next->value << endl;
    // cout << head->next->next->value;

    // print linked list

    print_linked_list(head);
     

    // -> means, (*node_1.value) we are defrencing the object's address to access those values


}