#include <iostream>
#include <queue>
using namespace std;
/*
queue follows fifo
Queue is a higher level Data Structure 
because it can be implented using other lower level data Strcutres 

Queue oprations 

1) PUSH 2) POP 3) SIZE 4)FRONT 5) EMPTY  6) BACK
*/
int main()
{
  queue<int> q;
  q.push(10) ; 

  cout <<q.front();
}