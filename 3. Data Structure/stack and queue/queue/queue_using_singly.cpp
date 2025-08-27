#include <iostream>
using namespace std;
/*
queue follows fifo
Queue is a higher level Data Structure 
because it can be implented using other lower level data Strcutres 

Queue oprations 

1) PUSH 2) POP 3) SIZE 4)FRONT 5) EMPTY  6) BACK
*/

class node{
    public:
    int value; 
    node* next;

    node(int val){
        this->value = val;
        this->next = NULL;
    }
};

class myQueue{
    public:
    node* head = NULL;
    node* tail = NULL;
    int cnt=0;  // to track the size 

    void push(int value){  // 0(1)
        cnt++;
        node* new_node = new node(value);

        if(head==NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        tail = new_node;
    }

    void pop(){

        cnt--;

        node* delete_node = head;
        head = head->next;
        delete delete_node;

        if(head == NULL){
            tail = NULL;
        }
    }
    
    int front(){
        return head->value;
    }

    int back(){
        return tail->value;
    }
    int size(){
        return cnt;
    }

    bool empty(){
        if(head==NULL) return true;
        else return false;
    }



};


int main()
{
    /*input
    3
10 20 30
*/
    myQueue q;
    int n; cin>>n;

    for(int i=0;i<n;i++){
        int value; cin>>value;
        q.push(value);
    }

    //check 
    cout << q.front() <<" " <<q.size() <<endl;

    // print all 
    while(!q.empty()){
        
        cout << q.front();
        q.pop();
    }


}