#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void list_input(list<string> &ll)
{
    string s;
    while (cin >> s && s != "end")
    {
        ll.push_back(s);
    }
}

void print_list(list<string> ll)
{

    for (string value : ll)
    {
        cout << value << " ";
    }
}

void remove_duplicates(list<int> &ll)
{
    ll.sort();
    ll.unique();
}

void Browser_History(list<string> &ll)
{

    int test;
    cin >> test;
    auto current = ll.end();

    string command;
    string address;

    while (test--)
    {

        cin >> command;

        if (command == "visit")
        {
            string address;
            cin >> address;

            auto it = find(ll.begin(), ll.end(), address);

            if (it == ll.end())
            { // NOT FOUND
                cout << "Not Available" << endl;
            }
            else
            { // FOUND
                current = it;
                cout << *it << endl;
            }
        }

        if (command == "prev")
        {
            // Find the address in the list

            if (current != ll.begin())
            {
                current = --current;
                cout << *current << endl;
            }

            else
            {
                cout << "Not Available" << endl;
            }
        }

       else if (command == "next")
        {
            if (current != ll.end())
            {
                auto next_it = current;
                next_it++;
                
                if (next_it != ll.end())
                {
                    current = next_it;
                    cout << *current << endl;
                }
                else
                {
                    cout << "Not Available" << endl;
                }
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }          
    }
}

void Remember_Previous_Queries()
{

    list<int> ll; 
    int q;
    cin >> q;

    while (q--)
    {
        int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            
            ll.push_front(v);
        }
        else if (x == 1)
        {
            // Insert at tail
            ll.push_back(v);
        }
        else if (x == 2)
        {
            // Delete at index v
            if (v >= 0 && v < ll.size())
            {
                auto it = next(ll.begin(), v); // Move iterator to vth position
                ll.erase(it);
            }
        }

        // Print left to right
        cout << "L -> ";
        for (auto it = ll.begin(); it != ll.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;

     
        cout << "R -> ";
        list<int> temp = ll; 
        temp.reverse();       
        for (auto it = temp.begin(); it != temp.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}

    int main()
    {
        // list<string> ll;
        // list_input(ll);

        // print_list(ll);
        // remove_duplicates(ll);
        // Browser_History(ll);

        // print_list(ll);
        Remember_Previous_Queries();
    }