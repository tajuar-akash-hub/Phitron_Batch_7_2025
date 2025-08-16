// #include <bits/stdc++.h>
#include <iostream>
using namespace std;


/*

notes includes 
1) each operatation steps 
2) each operations time complexity 
3) add a visual image, draw in draw.io

*/
class node
{

public:
    int value;
    node *next;

    node(int v)
    {
        this->value = v;
        this->next = NULL;
    }

    // default constructor
    node() {}
};

// insert at head
void insert_at_head(node *&head, int value)
{

    node *new_node = new node(value);

    new_node->value = value;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    new_node->next = head;

    // change the head
    head = new_node;

    // // head = new_node;
    // cout <<"address of head"<<" " << head <<endl;
    // cout <<"address of newnode"<<" " << new_node->next<<endl ;

    // complexity 0(1)
}

void insert_at_tail(node *&head, int value)
{

    /* Steps : 

    1) pass head by reference 

    *) check corner case if linkelist is null then make new node as only node

    */
    node *new_node = new node(value);
    new_node->value = value;

    // node *current_last_node;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        // cout<<temp->value<<endl;

        // cout<<temp->value<<" ";

        temp = temp->next;
    }
    

    // insert at tail
    temp->next = new_node;


    //    cout<<"printing final temp"<< temp->value<<endl;
}

void insert_at_tail_optimized(node *&head, node* &tail ,int value)
{

    /* Steps : 

    1) pass head by reference 

    *) check corner case if linkelist is null then make new node as only node

    */
    node *new_node = new node(value);
    new_node->value = value;

    
    // corner caser 

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }

    
    // insert at tail
    tail->next = new_node;
    tail = new_node;
    

    //    cout<<"printing final temp"<< temp->value<<endl;
}

// void insert_at_any_position_my_loigc(node *&head, int position, int value)
// {


//     // new node creation 
//     //steps 
//     /*
//     1) Create a new node 
//     2) imagine index, starts from 0 
//     */
   

//     node *new_node = new node(value);

//     node *current_node_at_given_pos = new node;
//     node *next_node_of_current_pos = new node;

//     node *temp = head;

//     int i = 0 ; 

//     while (temp != NULL)

     
//     {
//         // assigning value to current node, and next node 

//         if(i == position-1) {
//             current_node_at_given_pos = temp;
//             next_node_of_current_pos = temp->next;
//         }

//         // cout<<i<<" " <<temp->value<<endl;

//         // accesing current node at given pos


//         //increment
//         temp = temp->next;
//         i++;
//     }

//     // cout<<" printing "<<next_node_of_current_pos->value;

//     // make connection 

//     // cout<<current_node_at_given_pos->value <<" " << next_node_of_current_pos->value <<" " << new_node->value <<endl;

//     new_node->next = next_node_of_current_pos;
//     current_node_at_given_pos->next = new_node;


// }

void insert_at_any_position(node *&head, int position, int value)
{

    // new node creation 
    //steps 
    /*
    1) Create a new node 
    2) imagine index, starts from 0 
    */
   

    node *new_node = new node(value);
    node *temp = head;

    for(int i=0;i<position-1;i++){

        // cout<< temp->value<<endl;
        

        temp = temp->next;
        if (temp == NULL) return;

    }
    // cout<<"last value of temp" << temp->value;

    // make connection 
    new_node->next = temp->next;
    temp->next = new_node;

}

void print_linked_list(node *head)
{

    node *temp = head; // its not a copy, its hold the memory address of head

    while (temp != NULL)
    {
        cout << temp->value << endl;
        temp = temp->next;
    }
}

void print_linked_list_reverse(node *head)
{
    node *temp = head; // its not a copy, it holds the memory address of head
    if ( temp == NULL){
        return;
    }
    print_linked_list_reverse(temp->next);
    cout<< temp->value<<endl;
}

void input_linkedlist(node * &head, node * &tail){
   int value;
    while(1){
        cin >> value;
        // cout<<value <<" ";
        if(value == -1) break;
        // cout<<value;
        insert_at_tail_optimized(head,tail,value);
    }
}

void recursion_basic( int start, int size ){

    /* This code will print 1 to N */
    if (start == size ) return;
    recursion_basic(start+1,size);
    cout<< start <<endl;
}


// delete operation 
void delete_at_head(node * &head){
    
    if( head == NULL) return;

    node* delete_node = head;
    head = head->next;
    delete delete_node;
}
void delete_at_any_pos(node *&head,int pos){

    node * temp = head;
    for(int i=0;i<pos-1;i++){
        // cout<<temp->value<<endl;
        temp = temp->next;
    }

    node* delete_node = temp->next;

    temp->next = temp->next->next;

    delete delete_node;
}

// sort linkedlist using selection sort
void sort_linked_list(node *head)
{

    for (node *i = head; i->next != NULL; i = i->next)
    {


        for (node *j = i->next; j != NULL; j = j->next)
        {

            // cout<< i->value <<" " << j->value <<" "<<endl;
            if( i->value > j->value) swap(i->value,j->value);


        }
    }
    /* complexity O(N*N)*/

    print_linked_list(head);
}

// Function to create a deep copy of the doubly linked list
void copy_linkedlist(node* original_head, node*& copy_head, node*& copy_tail) {
    copy_head = NULL;
    copy_tail = NULL;
    
    node* temp = original_head;
    while(temp != NULL) {
        insert_at_tail(copy_head, copy_tail, temp->value);
        temp = temp->next;
    }
}

// 1st code reverse linkedlist 
void reverse(node * &head,node* &tail ,node* temp)
{
    // node *temp = head; 

    if (temp->next == NULL){
        head = temp;
        // cout<< temp->value<< " ";
        return;
    }

    reverse(head,tail,temp->next);
    // new_head->next = temp->next;
    temp->next->next = temp;
    temp->next = NULL;
    tail = temp;
    // cout<< temp->value<<endl;
}

// reverse by swapping value 
void reverse_by_swapping_value(node * &head,node* &tail ,node* temp)
{
    // node *temp = head; 

    if (temp->next == NULL){
        // head = temp;
        // cout<< temp->value<< endl;
        return;
    }

    reverse_by_swapping_value(head,tail,temp->next);
    // new_head->next = temp->next;
    // temp->next->next = temp;
    // temp->next = NULL;
    // tail = temp;
    swap(temp->value,temp->next->value);
    // cout<< temp->value<<endl;
}

// 2nd code reverse linkedlist  (doesn't work)
// void reverse_2nd(node * &head)
// {
//     node *temp = head; 

//     if (temp->next == NULL){
//         head = temp;
//         // cout<< temp->value<< " ";
//         return;
//     }

//     reverse_2nd(temp->next);
//     // new_head->next = temp->next;
//     temp->next->next = temp;
//     temp->next = NULL;
//     // cout<< temp->value<<endl;
// }


// cycle detecton
void cycle_detectin()
{
    // hair tortoise algoithm
    /*
    basic idea, i pointer moves, 1 step, j pointer moves 2 step
    if there is a cycle they will meet, otherwise j  will be at null
    */

    node *head = new node(10);
    node *a = new node(20);
    node *b = new node(30);
    node *c = new node(40);
    node *tail = new node(50);

    // connection
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = tail;
    tail->next = NULL;

    // print_linked_list(head);

    // cycle detection main
    // it also called slow fast algorithm 

    node *tortoise = head->next;
    node *hare = head->next->next;
    bool flag = false;

    while (hare->next != NULL && hare != NULL)
    {
        tortoise = tortoise->next ; 
        hare = hare->next->next;
        if(hare == tortoise){
            // cout<<" there is a cycle "; 
            // cout<< hare->value <<" "<< tortoise->value;
            flag = true;
            break;
        }
        
    }
    if ( flag == true)  cout <<"Cycle deletected" <<endl;
    else cout <<"NO Cycle deletected" <<endl;
}

int size(node *head)
{
    int size_cnt = 0;
    while (head != NULL)
    {
        // cout<<temp->val<<" "<<endl;
        size_cnt++;
        head = head->next;
    }

    return size_cnt;
}

int main()
{
    // take input with function 

    node * head = NULL;
    node * tail = NULL;

    // head->next = NULL;
    // tail->next = NULL;  

    input_linkedlist(head,tail);

    reverse(head,tail,head);

    // reverse_by_swapping_value(head,tail,head);

    // sort_linked_list(head);

    

    // delete_at_head(head);
    // delete_at_any_pos(head,2);
   

    print_linked_list(head);

    // print_linked_list(head);

    // cout <<"printint head's value after reverse"<<" " << head->value;


    // int value;
    // int a[6];
    // int i=0;

    // while(1){

    //     cin >> value;
    //     a[i] = value;
    //     // cout<<value <<" ";
    //     if(value == -1) break;
    //     // cout<<value;
    //     i++;
        
    // }


    // recursion_basic(1, 6);





    // my_class my_obj = my_class("Akash");

    // node my_obj_1(10),my_obj_2(20) , my_obj_3(30);

    // dynamic object

    // node *head = new node;
    // head = NULL;

    // node *head = new node(10);
    // node *a = new node(20);
    // node *b = new node(30);
    // node *c = new node(40);

    

    // // // connection

    // head->next = a;
    // a->next = b;
    // b->next = c;

    // insert_at_any_position(head, 1, 100);

    // insert_at_head(head, 5);
    // insert_at_tail(head, 40);
    // insert_at_tail(head, 60);

    // insert_at_tail(head, 70);


    // node* tail = c;

    // insert_at_tail_optimized(head,tail,200);

    // print_linked_list(head);

    // -> means, (*node_1.value) we are defrencing the object's address to access those values
    // cycle_detectin();
}