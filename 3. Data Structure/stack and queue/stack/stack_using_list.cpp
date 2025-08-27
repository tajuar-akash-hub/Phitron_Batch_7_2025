#include <iostream>
#include <list>
using namespace std;


class myStack
{
    public:
        list<int> ll;

        void push(int val)
        {
            ll.push_back(val);
        }
        void pop()
        {
            ll.pop_back();
        }
        int top()
        {
            return ll.back();
        }
        int size()
        {
            return ll.size();
        }
        bool empty()
        {
            return ll.empty();
        }
};


int main()
{
    /*
    Stack follows LIFO
    operations 
    1) push
    2) pop 
    3) empty 
    4) size
    */

    myStack st;

    int size;
    cin >> size;

    for(int i=0;i<size;i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

     
    // access top value 
    cout << st.empty();

    // pop
    

    // while(!st.empty())
    // {
    //     cout << st.top() << endl;
    //     st.pop();
    // }
    
    return 0;
    
}


