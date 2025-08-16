// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node
{

public:
    int value;
    node *next;
    node *previous;

    node(int v)
    {
        this->value = v;
        this->next = NULL;
        this->previous = NULL;
    }

    void display()
    {
        cout << value << " ";
    }

    // default constructor
    node() {}
};

// insert operations

// insert at head
void insert_at_head(node *&head, node *&tail, int value)
{

    node *new_node = new node(value);

    new_node->value = value;

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }

    head->previous = new_node;
    new_node->next = head;
    head = new_node;

    // change the head
    head = new_node;

    // // head = new_node;
    // cout <<"address of head"<<" " << head <<endl;
    // cout <<"address of newnode"<<" " << new_node->next<<endl ;

    // complexity 0(1)
}

void insert_at_tail(node *&head, node *&tail, int value)
{
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
    new_node->previous = tail;
    tail = new_node;
    //    cout<<"printing final temp"<< temp->value<<endl;
}

void insert_at_any_position(node *&head, int position, int value)
{
 
    node *new_node = new node(value);
    node *temp = head;

    for (int i = 0; i < position-1 ; i++)
    {
        
        // cout<< temp->value<<endl;
        temp = temp->next;
        if (temp == NULL)
            return;
    }

    // cout<<"last value of temp" << temp->value;
    // make connection
    // cout<<temp->value;

    // first part 
    new_node->next = temp->next;
    new_node->previous = temp;

    //2nd part 
    temp->next = new_node;

    // 3rd part 
    new_node->next->previous = new_node;

    
}


// delete operation 

void delete_at_head(node * &head, node* &tail){

    if( head == NULL) return;
   
    node* delete_node = head;
    head = head->next;
    delete delete_node;

    if(head == NULL){
        tail = NULL;
        return;
    }

    head->previous = NULL;
    
}
void delete_at_tail(node * &head, node* &tail){

//    cout <<"printing tail " <<tail->value <<endl;
  // keep the track to delete
   node* temp = tail ;

   tail = tail->previous;

   if(tail == NULL){
    head = NULL;
    return;
   }


   tail->next = NULL;

   delete temp;
    
}

void delete_at_any_position(node *&head,node* &tail,int position)
{
 
    node *temp = head;

    for (int i = 0; i < position-1 ; i++)
    {
        // cout<< temp->value<<endl;
        temp = temp->next;
        if (temp == NULL)
            return;
    }
    node* delete_node = temp->next;

    temp->next = temp->next->next;
    temp->next->previous = temp;

    delete delete_node;
    
}


// input doubly linkedlist 
void input_linkedlist(node * &head, node * &tail){
   int value;
    while(1){
        cin >> value;
        // cout<<value <<" ";
        if(value == -1) break;
        // cout<<value;
        insert_at_tail(head,tail,value);
    }
}




// print operations

void print_forward(node *head)
{

    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->value << endl;
        temp = temp->next;
    }
}

void print_backward(node *tail)
{

    node *temp = tail;

    while (temp != NULL)
    {
        cout << temp->value << endl;
        temp = temp->previous;
    }
}

//  You can easily reverse doubly linkedlist using two-pointers technique

void reverse(node *&head, node *&tail)
{
    for (node *i = head, *j = tail; i != NULL && i!=j; i = i->next, j = j->previous)
    {
       
        if (j->next != NULL && i->previous != NULL)
        {

            if (i == j->next || i->previous == j )
            {
                break;
            }
        }
       
        //  cout << i->value <<" " <<  j->value <<" " << endl;
         swap(i->value,j->value);
    }
}

// basic 
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





int main()
{
    // // manually let's node
    // node *head = new node(10);
    // node *a = new node(20);
    // node *b = new node(30);
    // node *tail = new node(40);

    // // next connection

    // head->next = a;
    // a->next = b;
    // b->next= tail;

    // // previous connection
    // a->previous = head;
    // b->previous = a;
    // tail->previous = b;

    // take input using function 

    node* head = NULL;
    node* tail = NULL;
    input_linkedlist(head,tail);

    reverse(head,tail); 
    print_forward(head);


    // print doubly linkedlist
    //   print_forward(head);
    cout<< endl;
    print_backward(tail);

    // insert_at_head(head,tail,50);
    // insert_at_tail(head, tail, 40);
    // insert_at_tail(head, tail, 60);

    // insert_at_any_position(head,2,25);
    // insert_at_any_position(head,3,100);

    //delete linkedlinst 

    // delete_at_head(head,tail);
    // delete_at_tail(head,tail);
    // delete_at_any_position(head,tail,2);

    //   print_forward(head);
    // print_forward(head);
    // cout<<endl;
    // print_backward(tail);
}