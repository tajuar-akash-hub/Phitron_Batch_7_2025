#include <iostream>
#include <list>
using namespace std;
/*
queue follows fifo
Queue is a higher level Data Structure 
because it can be implented using other lower level data Strcutres 

Queue oprations 

1) PUSH 2) POP 3) SIZE 4)FRONT 5) EMPTY  6) BACK
*/



class myQueue{
    public:
    list<int> dl;
   

    void push(int value){
        dl.push_back(value);
    }

    void pop(){

        dl.pop_front();
    }
    
    int front(){
        return dl.front();
    }

    int back(){
        return dl.back();
    }
    int size(){
        return dl.size();
    }

    bool empty(){
        return dl.empty();
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