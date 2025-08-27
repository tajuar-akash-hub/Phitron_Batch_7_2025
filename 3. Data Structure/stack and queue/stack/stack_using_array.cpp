#include <iostream>
#include <vector>
using namespace std;


class myStack
{
    public:
        vector<int> v;

        void push(int val)
        {
            v.push_back(val);
        }
        void pop()
        {
            v.pop_back();
        }
        int top()
        {
            return v.back();
        }
        int size()
        {
            return v.size();
        }
        bool empty()
        {
            return v.empty();
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

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    
    return 0;
    
}


