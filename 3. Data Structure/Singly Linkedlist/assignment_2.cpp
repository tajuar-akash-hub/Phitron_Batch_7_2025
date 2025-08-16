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

void insert_at_tail_optimized(node *&head, node *&tail, int value)
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
    // steps
    /*
    1) Create a new node
    2) imagine index, starts from 0
    */

    node *new_node = new node(value);
    node *temp = head;

    for (int i = 0; i < position - 1; i++)
    {

        // cout<< temp->value<<endl;

        temp = temp->next;
        if (temp == NULL)
            return;
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
        cout << temp->value<<" " ;
        temp = temp->next;
    }
}

void print_linked_list_reverse(node *head)
{
    node *temp = head; // its not a copy, it holds the memory address of head
    if (temp == NULL)
    {
        return;
    }
    print_linked_list_reverse(temp->next);
    cout << temp->value << endl;
}

void input_linkedlist(node *&head, node *&tail)
{
    int value;
    while (1)
    {
        cin >> value;
        // cout<<value <<" ";
        if (value == -1)
            break;
        // cout<<value;
        insert_at_tail_optimized(head, tail, value);
    }
}
int size_of_linkedlist(node *&head, node *&tail)
{
    int size=0;
    node* temp = head;
    while (temp!=NULL)
    {
        // cout<< temp->value<<" ";
        
        
        temp = temp->next;
        size++;
    }

    return size;
}

void recursion_basic(int start, int size)
{

    /* This code will print 1 to N */
    if (start == size)
        return;
    recursion_basic(start + 1, size);
    cout << start << endl;
}

// delete operation
void delete_at_head(node *&head)
{

    if (head == NULL)
        return;

    node *delete_node = head;
    head = head->next;
    delete delete_node;
}
void delete_at_any_pos(node *&head, int pos)
{
    // check if list is empty 
    if (head == NULL) return;

     // Special case: deleting head (position 0)
    if (pos == 0) {
        node *delete_node = head;
        head = head->next;
        delete delete_node;
        return;
    }

    node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        // cout<<temp->value<<endl;
        temp = temp->next;
    }

    // Check if the node to delete exists
    if (temp->next == NULL) {
        return;
    }

    node *delete_node = temp->next;

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
            if (i->value > j->value)
                swap(i->value, j->value);
        }
    }
    /* complexity O(N*N)*/

    print_linked_list(head);
}

// exam questions

void get_difference()
{

    node *head = NULL;
    node *tail = NULL;
    input_linkedlist(head, tail);

    int max = head->value;
    int min = head->value;

    for (node *i = head; i != NULL; i = i->next)
    {
        if (i->value > max)
            max = i->value;
        if (i->value < min)
            min = i->value;
    }

    // print_linked_list(head);
    cout << max - min << " ";
    // cout<<min<<endl;
}

void Search()
{
    int test;
    cin >> test;

    while (test--)
    {
        node *head = NULL;
        node *tail = NULL;
        input_linkedlist(head, tail);
        // print_linked_list(head);
        // cout << endl;
        int x;
        cin >> x;

        // search the number
        node *temp = head; //
        int indx = 0;
        int flag = 0;

        while (temp != NULL)
        {
            if (temp->value == x)
            {
                cout << indx<<endl;
                flag = 1;
                break;
            }

            temp = temp->next;
            indx++;
        }

        // binary search 

        // corner case 
        if (head == NULL) cout<<"-1"<<endl;
        if (flag == 0) cout<<"-1"<<endl;
        // if (flag == 1) cout<<"-1"<<endl;
    

        
    }
}

void Same_to_Same()
{
    // first linikedlist
    node *head1 = NULL;
    node *tail1 = NULL;
    input_linkedlist(head1, tail1);

    // second linkedlist
    node *head2 = NULL;
    node *tail2 = NULL;
    input_linkedlist(head2, tail2);

    // print
    // print_linked_list(head1);
    // print_linked_list(head2);

    // check they are same or not
    node *temp1 = head1;
    node *temp2 = head2;
    bool flag = true;

    if (size_of_linkedlist(head1, tail1) != size_of_linkedlist(head2, tail2))
        {
            cout << "NO" << endl;
            return;
        }

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->value != temp2->value)
        {
            flag = false;
            cout << "NO" << endl;
            return;
        }
        // cout<<temp1->value <<" " << temp2->value <<" "<<endl;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    cout<<"YES" <<endl;

    // cout << size_of_linkedlist(head2,tail2) ;
}

void Queries(){


    node* head = NULL;
    node* tail = NULL;

    int test; cin >>test; 
    while(test--) {

        int x , v ; cin>> x >> v;

        if(x == 0 ) {
            insert_at_head(head,v);
        }

        if(x == 1 ) {
            insert_at_tail(head,v);
        }

        if(x == 2 ) {
            if ( v<0 ||  v > size_of_linkedlist(head,tail) ) {
                print_linked_list(head);
                cout<<endl;
                continue;
            }
        
        delete_at_any_pos(head,v);
        }
        print_linked_list(head);

        cout<<endl;



         
    }

}

// void remove_duplicates()
// {
//     node *head = NULL;
//     node *tail = NULL;
//     input_linkedlist(head, tail);
//     // print_linked_list(head);

//     node* temp_head = NULL;
//     node* temp_tail = NULL;

//     int indx = 0;

//     for (node* i = head; i->next != NULL; i = i->next)
//     {
        

//         for (node* j = i->next; j!= NULL; j = j->next)
//         {
//             if ( i->value == j->value ) {
//                 // cout << i->value <<" " << j->value<<" "<<indx<< endl;
//                 delete_at_any_pos(head,indx);
//             }
            
//         }
//         indx++;
        
//     }
//     // if (flag == 1) print_linked_list(temp_head);
//     print_linked_list(head);

// }

void remove_duplicates() {
    
    node *head = NULL;
    node *tail = NULL;
    input_linkedlist(head, tail);
    
    // If empty list, just print empty
    if (head == NULL) {
        print_linked_list(head);
        return;
    }
    
    // let's start from the first node 
    node* current = head;
    
    while (current != NULL) {
        // Look at all nodes after current
        node* runner = current;
        
        while (runner->next != NULL) {
            // If next node has same value as current
            if (runner->next->value == current->value) {
                // Delete the duplicate
                node* duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
            } else {
                // Move to next node
                runner = runner->next;
            }
        }
        // move curretn as well
        current = current->next;
    }
    
    print_linked_list(head);
}

int main()
{
    // get_difference();
    // Search();
    // Same_to_Same();
    // Queries();
    remove_duplicates();
}