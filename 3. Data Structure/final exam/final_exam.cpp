#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
using namespace std;

class Student
{
public:
    string name;
    long long int roll;
    long long int marks;
    Student(string n, long long int roll, long long marks)
    {
        this->name = n;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp
{
public:
    bool operator()(Student l, Student r)
    {
        if (l.marks < r.marks)
            return true;
        else if (l.marks > r.marks)
            return false;
        else if (l.marks == r.marks)
            return l.roll > r.roll;

        return false;
    }
};

void sorted()
{
    int test;
    cin >> test;

    while (test--)
    {
        int size;
        cin >> size;
        set<int> s;
        while (size--)
        {
            int value;
            cin >> value;
            s.insert(value);
        }

        // print set

        for (auto it = s.begin(); it != s.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}
// void pairs()
// {
//     int test;
//     cin >> test;
//     priority_queue<Student, vector<Student>, cmp> pq;
//     while (test--)
//     {

//         string s;
//         int num;
//         cin >> s >> num;
//         Student obj(s, num);
//         pq.push(obj);
//     }

//     // print priority queue
//     while (!pq.empty())
//     {
//         cout << pq.top().name << " " << pq.top().number << " " << endl;
//         pq.pop();
//     }
// }

void Count_Me()
{
    int test;
    cin >> test;
    cin.ignore();
    while (test--)
    {
        map<string, long long int> mp;
        string s;

        getline(cin, s);
        stringstream ss(s);
        string word;

        // for the second logic
        string mx_word = "";
        long long int max_count = 0;

        while (ss >> word)
        {
            // cout << word <<endl;
            mp[word]++;

            if (mp[word] > max_count)
            {
                mx_word = word;
                max_count = mp[word];
            }
        }

        cout << mx_word << " " << max_count << endl;

        // // find the max
        // auto max = mp.begin();
        // // int max_number = max->second;
        // // cout << max_number;

        // for (auto it = mp.begin(); it != mp.end(); it++)
        // {
        //     cout << it->first << " " << it->second << " " << endl;
        // }
        // cout << max->first <<" "<<max->second<<endl;
    }
}

void give_current_min()
{
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    long long int size;
    cin >> size;
    while (size--)
    {
        long long int value;
        cin >> value;
        pq.push(value);
    }

    int test;
    cin >> test;
    while (test--)
    {
        long long int value;
        cin >> value;
        if (value == 0)
        {
            long long int x;
            cin >> x;
            pq.push(x);
            cout << pq.top() << endl;
        }
        if (value == 1)
        {
            if (!pq.empty())
            {
                cout << pq.top() << endl;
            }
            if (pq.empty())
            {
                cout << "Empty" << endl;
            }
        }
        if (value == 2)
        {
            if (!pq.empty())
            {
                pq.pop();
                if (!pq.empty())
                    cout << pq.top() << endl;
            }
            if (pq.empty())
                cout << "Empty" << endl;
        }
    }
}
void give_current_max()
{
    priority_queue<Student, vector<Student>, cmp> pq;
    long long int size;
    cin >> size;
    while (size--)
    {
        string name;
        long long int roll;
        long long int marks;
        cin >> name >> roll >> marks;
        Student obj(name, roll, marks);
        pq.push(obj);
    }

    int queries;
    cin >> queries;

    while (queries--)
    {
        int value;
        cin >> value;

        if (value == 0)
        {
            string name;
            long long int roll;
            long long int marks;
            cin >> name >> roll >> marks;
            Student obj(name, roll, marks);
            pq.push(obj);
            cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
            
           
        }

        if (value == 1)
        {
            if (!pq.empty())
            {
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
            }
            else
                cout << "Empty" << endl;
        }

        if (value == 2)
        {
            if (!pq.empty())
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
            }
            else
                cout << "Empty" << endl;
        }
    }
}

int main()
{

    // sorted();
    // pairs();
    // Count_Me();
    // give_current_min();
    give_current_max();
}