#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int val) // O(1)
    {
        sz++;
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    void pop() // O(1)
    {
        sz--;
        Node *deletenode = tail;
        tail = tail->prev;
        delete deletenode;
        if (tail == NULL)
        {
            head = NULL;
            return;
        }
        tail->next = NULL;
    }
    int top() // O(1)
    {
        return tail->val;
    }
    int size() // O(1)
    {
        return sz;
    }
    bool empty() // O(1)
    {
        return head == NULL;
    }
};

class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int cnt = 0; // to track the size

    void push(int value)
    { // 0(1)

        cnt++;
        Node *new_node = new Node(value);

        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void pop()
    {

        cnt--;

        Node *delete_node = head;
        head = head->next;

        delete delete_node;

        if (head == NULL)
        {
            tail = NULL;
            return;
        }
        head->prev = NULL;
    }

    int front()
    {
        return head->val;
    }

    int back()
    {
        return tail->val;
    }
    int size()
    {
        return cnt;
    }

    bool empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
};

bool same_or_not_2()
{

    myStack s;
    myQueue q;

    int size1;
    cin >> size1;
    int size2;
    cin >> size2;

    if (size1 != size2)
        return false;

    while (size1--)
    {
        int value;
        cin >> value;
        s.push(value);
    }

    while (size2--)
    {
        int value;
        cin >> value;
        q.push(value);
    }

    // check
    while (!s.empty() && !q.empty())
    {

        if (s.top() != q.front())
            return false;

        s.pop();
        q.pop();
    }
    return true;
}

void is_it_valid()
{
    int test;
    queue<int> q;
    stack<char> s;

    cin >> test;

    while (test--)
    {
        string str;
        cin >> str;
        stack<char> s;

    

       for(char c : str)
        {
            cout <<"value of char " <<c << " ";

            if (!s.empty())
            {
                cout << "value of stack " << s.top() <<endl;
                if (c == '1' && s.top() == '0') s.pop();
                else if (c == '0' && s.top() == '1') s.pop();
                else {
                    cout<<"i am here ";
                    s.push(c);
                }
            }

            else{
                s.push(c);
            }
            
        }

        cout << (s.empty() ? "YES" : "NO") << endl;

    }

}

void special_queris(){

    int test; cin >> test;

    queue<string> q;

    while(test--){

        int command; cin >> command;
        

        if(command == 0 ) {
            string str; cin >>str;
            q.push(str);
        }

        else if (command == 1)
        {

            if (!q.empty())
            {
                string name = q.front();
                q.pop();
                cout << name << endl;
            }
            else
                cout << "Invalid" << endl;
        }
    }

}


// elimination 
void elimination()
{
    int test;
    stack<char> s;

    cin >> test;

    while (test--)
    {
        string str;
        cin >> str;
        stack<char> s;

    

       for(char c : str)
        {

            if (!s.empty())
            {
               
                if (c == '1' && s.top() == '0') s.pop();
                else {
                    s.push(c);
                }
            }

            else{
                s.push(c);
            }
            
        }

        cout << (s.empty() ? "YES" : "NO") << endl;

    }

}

int main()
{
//    is_it_valid();
    // special_queris();
    elimination();
}