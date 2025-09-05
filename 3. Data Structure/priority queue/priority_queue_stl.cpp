#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// how to sort object

class Student
{
public:
    string name;
    int roll;
    double marks;
    Student(string n, int r, double m)
    {
        this->name = n;
        this->roll = r;
        this->marks = m;
    }
};

class cmp
{
public:
    bool operator()(Student l, Student r)
    {
        if (l.marks > r.marks)
            return true;
        else if (l.marks < r.marks)
            return false;
        else
            return l.roll > r.roll;
    }
};

void sort_object_using_priority_queue()
{
    priority_queue<Student, vector<Student>, cmp> pq;

    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        string name;
        int roll;
        double marks;

        cin >> name >> roll >> marks;

        Student Obj(name, roll, marks);

        pq.push(Obj);
    }

    while(!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        pq.pop();
    }
}

int main()
{
    sort_object_using_priority_queue();
    /*
    Priority queue is the stl of Heap,
    the library <queue>
    */

    // priority_queue<int> pq; // by default its a max heap

    // // priority_queue<int , vector<int>, greater<int> > pq ; // by default its a max heap

    // pq.push(10);
    // pq.push(20);
    // pq.push(30);

    // // max heap
    // // as unlike queue priority queue doesn't work with back, so its only has top
    // cout << pq.top();
}