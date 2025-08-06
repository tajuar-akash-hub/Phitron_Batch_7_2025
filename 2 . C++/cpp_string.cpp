// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void string_capacity_functions()
{
    string s = "Mahir Tajuar Akash";

    // size

    cout << s.size() << endl;
    ;

    // capacity
    cout << s.capacity() << endl;
    ;

    // clear

    // s.clear();

    // empty

    string s1 = " ";
    s1.clear();

    if (s1.empty() == true)
        cout << "yes";
    else
        cout << "no";

    // resize
    cout << "String resize" << endl;

    string s2 = "This is Akash";
    s2.resize(5);
    cout << s2;

    // resize with imputation
    string s3 = "hey i am about to be resized";

    s3.resize(30, 'x');

    cout << s3;
    // cout<<s.max_size();
}

void string_element_access()
{

    string s1 = "Akash";

    // back
    cout << s1.back() << endl;

    // front
    cout << s1.front() << endl;
}

void string_modify()
{

    // append another string
    string s1 = "Mahir";
    s1 += " Tajuar";
    cout << s1 << endl;

    // append function
    s1.append(" Akash");

    cout << s1 << endl;

    // push back

    s1.push_back('l');

    cout << s1 << endl;
}

void string_iterator()
{

    string name = "Akash is my name";

    // begin() end() , both are pointers

    /*

     s.begin() returns an iterator, which is an object that:

    Points to the first character of the string

     Can be incremented (it++) to move forward

 Supports dereferencing (*it) to get the character

    */

    cout << *name.begin() << endl;
    cout << *(name.end() - 1) << endl;

    // traverse using iterator

    for (string::iterator it = name.begin(); it < name.end(); it++)
    {
        cout << *it << endl;
    }

    // same thing using auto

    cout << "printing using auto" << endl;

    for (auto it = name.begin(); it < name.end(); it++)
    {
        cout << *it << endl;
    }

    // why have to use string:: iterator , why not only character type pointer?
    /* Because iterat*rs is not just an pointer */
    cout << "printing witout string :: iterator" << endl;
}

void string_input_with_space()
{
    string s;

    // cin.ignore();  // to ignore previous character

    getline(cin, s);

    cout << s;

    // getline problem
    // can't ignore "Enter" like 'cin'
}

void string_stream()
{

    string str;

    getline(cin, str);

    stringstream s(str);
    string word;

    while (s >> word)
    {
        cout << word << endl;
    }
}

void string_constructor(){

    // way 1 
    string s("Akash");
    cout<<s<<endl;

    //way  2 
    string s1("Akash",2);  //resize
    cout<<s1;

    //way 3 
    string s3(5,'A'); //string of 5 A 
    cout<<s3;


}

void string_sort(){
    string s = "Akash";
    sort(s.begin(),s.end());

    cout<<s;


}

void string_reverse(){

    string s = "Akash";
    reverse(s.begin(),s.end());

    cout<<s;


}


int main()
{
    // string_capacity_functions();
    // string_element_access();
    // string_modify();
    // string_iterator();
    // string_input_with_space();
    // string_stream();
    // string_constructor();
    // string_sort();
    string_reverse();
}